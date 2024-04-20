//
// Implementation of functions for displaying Error message boxes.
//

#include <cstdio>
#include <string>

#include "oslib/os.h"
#include "oslib/wimp.h"
#include "oslib/wimpspriteop.h"
#include "salib/caret.h"
#include "salib/character.h"
#include "salib/errormessage.h"
#include "salib/exception.h"
#include "salib/iconbuilder.h"
#include "salib/rectangle.h"
#include "salib/reporter.h"
#include "salib/window.h"
#include "salib/windowbuilder.h"


static void CheckForErrors(const os_error* const error)
{
   if (error) {
      char exceptMsg[256];
      snprintf(exceptMsg, sizeof(exceptMsg), "%s (Error code: 0x%04X)", error->errmess, error->errnum);
      throw SALib::FatalException(exceptMsg);
   }
}


namespace SALib {

namespace Wimp {

namespace ErrorMessage {

//----------------------------------------------------------------------

void ReportFatal(const char * const applicationName, const char * const spriteName, const char * const message)
{
   // TODO - Identify an appropriate error number.

   os_error error;
   error.errnum = 255;
   snprintf(error.errmess, os_ERROR_LIMIT, "%s", message);

   const wimp_error_box_flags flags = wimp_ERROR_BOX_CANCEL_ICON | wimp_ERROR_BOX_GIVEN_CATEGORY
                                    | (wimp_ERROR_BOX_CATEGORY_ERROR << wimp_ERROR_BOX_CATEGORY_SHIFT);

   wimp_report_error_by_category(&error, flags, applicationName, spriteName, wimpspriteop_AREA, NULL);
}


//----------------------------------------------------------------------


static WindowBuilder BuildWindow(const std::string& applicationName,
                                 const Colour::Colour foregroundColour, const Colour::Colour backgroundColour)
{
   char windowTitle[80] = {'\0'};
   snprintf(windowTitle, sizeof(windowTitle), "Message from %s Application", applicationName.c_str());

   WindowBuilder::WindowFlagsBuilder windowFlags;
   windowFlags.SetMovable();
   windowFlags.SetAutoRedraw();
   windowFlags.SetForceWindowToStayOnScreen();
   windowFlags.SetHasTitleBar();

   WindowBuilder windowBuilder;

   windowBuilder.SetWindowFlags(windowFlags);
   windowBuilder.SetWindowTitle(windowTitle);

   windowBuilder.SetWindowExtentWidth( 800 + 100);
   windowBuilder.SetWindowExtentHeight(500 + 100);

   windowBuilder.SetWindowVisibleWidth( 800);
   windowBuilder.SetWindowVisibleHeight(500);

   windowBuilder.SetWindowXScrollOffset(50);
   windowBuilder.SetWindowYScrollOffset(-50);
   
   windowBuilder.SetWindowWorkAreaForegroundColour(foregroundColour);
   windowBuilder.SetWindowWorkAreaBackgroundColour(backgroundColour);

   return windowBuilder;
}

static IconBuilder BuildSpriteIcon(const std::string& spriteName, const SALib::Wimp::Rectangle& iconExtent,
                                   const Colour::Colour foregroundColour, const Colour::Colour backgroundColour)
{
   IconBuilder iconBuilder;

   iconBuilder.SetExtent(iconExtent);

   iconBuilder.GetIconFlagsBuilder().SetIconSprite();
   iconBuilder.GetIconFlagsBuilder().SetIconHCentred();
   iconBuilder.GetIconFlagsBuilder().SetIconVCentred();
   iconBuilder.GetIconFlagsBuilder().SetIconFGColour(foregroundColour);
   iconBuilder.GetIconFlagsBuilder().SetIconBGColour(backgroundColour);
   iconBuilder.GetIconFlagsBuilder().SetButtonType(SALib::Wimp::IconFlagsBuilder::IgnoreAllClicks);

   iconBuilder.GetIconDataBuilder().SetSpriteName(spriteName);

   return iconBuilder;
}

static IconBuilder BuildApplicationIcon(const std::string& spriteName,
                                        const Colour::Colour foregroundColour, const Colour::Colour backgroundColour)
{
   Rectangle iconExtent = { 70, -100, 138, -168 };
   return BuildSpriteIcon(spriteName, iconExtent, foregroundColour, backgroundColour);
}

static IconBuilder BuildCategoryIcon(const std::string& spriteName,
                                        const Colour::Colour foregroundColour, const Colour::Colour backgroundColour)
{
   SALib::Wimp::Rectangle iconExtent = { 70, -230, 138, -268 };
   return BuildSpriteIcon(spriteName, iconExtent, foregroundColour, backgroundColour);
}


static IconBuilder BuildMessageIcon(const std::string& message, const Colour::Colour foregroundColour, const Colour::Colour backgroundColour)
{
   IconBuilder iconBuilder;

   const int xOffset = 50;

   Rectangle iconExtent = { 138 + xOffset , -100, 800 - xOffset, -268 };
   iconBuilder.SetExtent(iconExtent);

   iconBuilder.GetIconFlagsBuilder().SetIconText();
   iconBuilder.GetIconFlagsBuilder().SetIconIndirected();
   iconBuilder.GetIconFlagsBuilder().SetIconHCentred();
   iconBuilder.GetIconFlagsBuilder().SetIconVCentred();
   iconBuilder.GetIconFlagsBuilder().SetIconFGColour(foregroundColour);
   iconBuilder.GetIconFlagsBuilder().SetIconBGColour(backgroundColour);
   iconBuilder.GetIconFlagsBuilder().SetButtonType(SALib::Wimp::IconFlagsBuilder::IgnoreAllClicks);

   iconBuilder.GetIconDataBuilder().SetValidation("L");
   iconBuilder.GetIconDataBuilder().SetText(message);

   return iconBuilder;
}

static IconBuilder BuildGroupBoxIcon(const Colour::Colour foregroundColour, const Colour::Colour backgroundColour)
{
   IconBuilder iconBuilder;

   Rectangle iconExtent = { -10 , -370, 820, -498 };
   iconBuilder.SetExtent(iconExtent);

   iconBuilder.GetIconFlagsBuilder().SetIconText();
   iconBuilder.GetIconFlagsBuilder().SetIconIndirected();
   iconBuilder.GetIconFlagsBuilder().SetIconHCentred();
   iconBuilder.GetIconFlagsBuilder().SetIconVCentred();
   iconBuilder.GetIconFlagsBuilder().SetIconBorder();
   iconBuilder.GetIconFlagsBuilder().SetIconFGColour(foregroundColour);
   iconBuilder.GetIconFlagsBuilder().SetIconBGColour(backgroundColour);
   iconBuilder.GetIconFlagsBuilder().SetButtonType(SALib::Wimp::IconFlagsBuilder::IgnoreAllClicks);
                                                     
   iconBuilder.GetIconDataBuilder().SetValidation("R4");
   iconBuilder.GetIconDataBuilder().SetText("");

   return iconBuilder;
}

static IconBuilder BuildDefaultActionButtonIcon(const Colour::Colour foregroundColour, const Colour::Colour backgroundColour)
{
   IconBuilder iconBuilder;

   const int width = 214;
   const int height = 68;

   const int right = 770;
   const int middleY  = -500 + ((500 - 370) / 2);

   Rectangle iconExtent = { right - width , middleY - (height / 2), right, middleY + (height / 2) };
   iconBuilder.SetExtent(iconExtent);

   iconBuilder.GetIconFlagsBuilder().SetIconText();
   iconBuilder.GetIconFlagsBuilder().SetIconIndirected();
   iconBuilder.GetIconFlagsBuilder().SetIconHCentred();
   iconBuilder.GetIconFlagsBuilder().SetIconVCentred();
   iconBuilder.GetIconFlagsBuilder().SetIconBorder();
   iconBuilder.GetIconFlagsBuilder().SetIconFGColour(foregroundColour);
   iconBuilder.GetIconFlagsBuilder().SetIconBGColour(backgroundColour);
   iconBuilder.GetIconFlagsBuilder().SetButtonType(SALib::Wimp::IconFlagsBuilder::ClickOnce);
                                                     
   iconBuilder.GetIconDataBuilder().SetValidation("R6,3");
   iconBuilder.GetIconDataBuilder().SetText("Continue");

   return iconBuilder;
}

static IconBuilder BuildStandardActionButtonIcon(const Colour::Colour foregroundColour, const Colour::Colour backgroundColour)
{
   IconBuilder iconBuilder;

   const int width = 200;
   const int height = 52;

   const int right = 770 - 214 - 20;
   const int middleY  = -500 + ((500 - 370) / 2);

   Rectangle iconExtent = { right - width , middleY - (height / 2), right, middleY + (height / 2) };
   iconBuilder.SetExtent(iconExtent);

   iconBuilder.GetIconFlagsBuilder().SetIconText();
   iconBuilder.GetIconFlagsBuilder().SetIconIndirected();
   iconBuilder.GetIconFlagsBuilder().SetIconHCentred();
   iconBuilder.GetIconFlagsBuilder().SetIconVCentred();
   iconBuilder.GetIconFlagsBuilder().SetIconBorder();
   iconBuilder.GetIconFlagsBuilder().SetIconFGColour(foregroundColour);
   iconBuilder.GetIconFlagsBuilder().SetIconBGColour(backgroundColour);
   iconBuilder.GetIconFlagsBuilder().SetButtonType(SALib::Wimp::IconFlagsBuilder::ClickOnce);
                                                     
   iconBuilder.GetIconDataBuilder().SetValidation("R5,3");
   iconBuilder.GetIconDataBuilder().SetText("Cancel");

   return iconBuilder;
}


NonBlockingErrorWindow::NonBlockingErrorWindow(Task& task, const std::string& applicationName, const std::string& spriteName,
                                               const Colour::Colour foregroundColour, const Colour::Colour backgroundColour)
   :   Window(BuildWindow(applicationName, foregroundColour, backgroundColour)),
       m_task(task),
       m_applicationName(applicationName),
       m_spriteName(spriteName),
       m_foregroundColour(foregroundColour),
       m_backgroundColour(backgroundColour),
       m_applicationIcon(BuildApplicationIcon(spriteName, foregroundColour, backgroundColour), *this),
       m_categoryIcon(BuildCategoryIcon("error", foregroundColour, backgroundColour), *this),
       m_messageIcon(BuildMessageIcon("This is a dummy message.", foregroundColour, backgroundColour), *this, 80 /* max text size */),
       m_groupBoxIcon(BuildGroupBoxIcon(foregroundColour, backgroundColour), *this),
       m_defaultActionButtonIcon(BuildDefaultActionButtonIcon(foregroundColour, backgroundColour), *this),
       m_standardActionButtonIcon(BuildStandardActionButtonIcon(foregroundColour, backgroundColour), *this)
{

}

ButtonClicked NonBlockingErrorWindow::ShowOK(const std::string& message)
{
   m_standardActionButtonIcon.Hide();
   m_defaultActionButtonIcon.Unhide();

   m_defaultActionButtonIcon.GetRawTextString().clear();
   m_defaultActionButtonIcon.GetRawTextString() = "OK";

   m_messageIcon.GetRawTextString().clear();
   m_messageIcon.GetRawTextString() = message.substr(0, message.size() > 80 ? 80 : message.size()).c_str();

   (void)Show();

   return OK_CLICKED;
}

ButtonClicked NonBlockingErrorWindow::ShowContinue(const std::string& message)
{
   m_standardActionButtonIcon.Hide();
   m_defaultActionButtonIcon.Unhide();

   m_defaultActionButtonIcon.GetRawTextString().clear();
   m_defaultActionButtonIcon.GetRawTextString() = "Continue";

   m_messageIcon.GetRawTextString().clear();
   m_messageIcon.GetRawTextString() = message.substr(0, message.size() > 80 ? 80 : message.size()).c_str();

   (void)Show();

   return CONTINUE_CLICKED;
}

ButtonClicked NonBlockingErrorWindow::ShowCancelContinue(const std::string& message)
{
   m_standardActionButtonIcon.Unhide();
   m_defaultActionButtonIcon.Unhide();

   m_defaultActionButtonIcon.GetRawTextString().clear();
   m_defaultActionButtonIcon.GetRawTextString() = "Continue";

   m_standardActionButtonIcon.GetRawTextString().clear();
   m_standardActionButtonIcon.GetRawTextString() = "Cancel";

   m_messageIcon.GetRawTextString().clear();
   m_messageIcon.GetRawTextString() = message.substr(0, message.size() > 80 ? 80 : message.size()).c_str();

   return (&Show()) == (&m_defaultActionButtonIcon) ? CONTINUE_CLICKED : CANCEL_CLICKED;
}

ButtonClicked NonBlockingErrorWindow::ShowCancelOK(const std::string& message)
{
   m_standardActionButtonIcon.Unhide();
   m_defaultActionButtonIcon.Unhide();

   m_defaultActionButtonIcon.GetRawTextString().clear();
   m_defaultActionButtonIcon.GetRawTextString() = "OK";

   m_standardActionButtonIcon.GetRawTextString().clear();
   m_standardActionButtonIcon.GetRawTextString() = "Cancel";

   m_messageIcon.GetRawTextString().clear();
   m_messageIcon.GetRawTextString() = message.substr(0, message.size() > 80 ? 80 : message.size()).c_str();
  
   return (&Show()) == (&m_defaultActionButtonIcon) ? OK_CLICKED : CANCEL_CLICKED;
}

const Icon& NonBlockingErrorWindow::Show(void)
{
   Open();
   Caret::SetPositionNoIcon(*this, 10, 10, false);

   const wimp_poll_flags wimpPollFlags = wimp_MASK_NULL | wimp_MASK_LEAVING | wimp_MASK_ENTERING
                                       | wimp_MASK_LOSE | wimp_MASK_GAIN    | wimp_MASK_POLLWORD;

   wimp_block wimpBlock = { 0 };
   wimp_event_no reason = 0;

   while (!m_task.RequestToQuitReceived()) {  // temporary - needs to be set to true
      CheckForErrors(xwimp_poll(wimpPollFlags, &wimpBlock, NULL, &reason));

      switch (reason) {

         case wimp_USER_MESSAGE:
         case wimp_USER_MESSAGE_RECORDED:
            if (wimpBlock.message.action == message_QUIT) {
               m_task.RequestToQuit();
            }
            break;

         case wimp_OPEN_WINDOW_REQUEST:
             if (IsMessageForMe(reinterpret_cast<unsigned>(wimpBlock.open.w))) {
                OpenRequest(reinterpret_cast<unsigned*>(&wimpBlock));
             }
             break;

         case wimp_MOUSE_CLICK:
             if (IsMessageForMe(reinterpret_cast<unsigned>(wimpBlock.pointer.w))) {
                if (wimpBlock.pointer.buttons == wimp_CLICK_SELECT ||
                    wimpBlock.pointer.buttons == wimp_CLICK_ADJUST) {

                   if (static_cast<int>(wimpBlock.pointer.i) == m_defaultActionButtonIcon.GetIconHandle()) {
                      Close();
                      return m_defaultActionButtonIcon;
                   }

                   if (static_cast<int>(wimpBlock.pointer.i) == m_standardActionButtonIcon.GetIconHandle()) {
                      Close();
                      return m_standardActionButtonIcon;
                   }
                }
             }
             break;

         case wimp_KEY_PRESSED:
             if (IsMessageForMe(reinterpret_cast<unsigned>(wimpBlock.key.w))) {
                if (static_cast<int>(wimpBlock.key.c) == CharacterCode::Enter) {
                   Close();
                   return m_defaultActionButtonIcon;
                }

                if (static_cast<int>(wimpBlock.key.c) == CharacterCode::Escape) {
                   Close();
                   return m_standardActionButtonIcon;
                }
             }
             break;
      }
   }

}



//----------------------------------------------------------------------
}

}

}