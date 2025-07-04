/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

Screen1ViewBase::Screen1ViewBase() :
    flexButtonCallback(this, &Screen1ViewBase::flexButtonCallbackHandler),
    buttonCallback(this, &Screen1ViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 240, 320);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    flexButton1.setBoxWithBorderPosition(0, 0, 50, 50);
    flexButton1.setBorderSize(5);
    flexButton1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1.setText(TypedText(T___SINGLEUSE_QUGK));
    flexButton1.setTextPosition(0, 0, 50, 50);
    flexButton1.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton1.setAction(flexButtonCallback);
    flexButton1.setPosition(30, 73, 50, 50);
    add(flexButton1);

    flexButton4.setBoxWithBorderPosition(0, 0, 50, 50);
    flexButton4.setBorderSize(5);
    flexButton4.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton4.setText(TypedText(T___SINGLEUSE_D3TL));
    flexButton4.setTextPosition(0, 0, 50, 50);
    flexButton4.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton4.setAction(flexButtonCallback);
    flexButton4.setPosition(30, 135, 50, 50);
    add(flexButton4);

    flexButton7.setBoxWithBorderPosition(0, 0, 50, 50);
    flexButton7.setBorderSize(5);
    flexButton7.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton7.setText(TypedText(T___SINGLEUSE_4KGN));
    flexButton7.setTextPosition(0, 0, 50, 50);
    flexButton7.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton7.setAction(flexButtonCallback);
    flexButton7.setPosition(30, 201, 50, 50);
    add(flexButton7);

    flexButton8.setBoxWithBorderPosition(0, 0, 50, 50);
    flexButton8.setBorderSize(5);
    flexButton8.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton8.setText(TypedText(T___SINGLEUSE_75KY));
    flexButton8.setTextPosition(0, 0, 50, 50);
    flexButton8.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton8.setAction(flexButtonCallback);
    flexButton8.setPosition(95, 201, 50, 50);
    add(flexButton8);

    flexButton6.setBoxWithBorderPosition(0, 0, 50, 50);
    flexButton6.setBorderSize(5);
    flexButton6.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton6.setText(TypedText(T___SINGLEUSE_AJ80));
    flexButton6.setTextPosition(0, 0, 50, 50);
    flexButton6.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton6.setAction(flexButtonCallback);
    flexButton6.setPosition(160, 135, 50, 50);
    add(flexButton6);

    flexButton9.setBoxWithBorderPosition(0, 0, 50, 50);
    flexButton9.setBorderSize(5);
    flexButton9.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton9.setText(TypedText(T___SINGLEUSE_WVM1));
    flexButton9.setTextPosition(0, 0, 50, 50);
    flexButton9.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton9.setAction(flexButtonCallback);
    flexButton9.setPosition(160, 201, 50, 50);
    add(flexButton9);

    flexButton5.setBoxWithBorderPosition(0, 0, 50, 50);
    flexButton5.setBorderSize(5);
    flexButton5.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton5.setText(TypedText(T___SINGLEUSE_ERMR));
    flexButton5.setTextPosition(0, 0, 50, 50);
    flexButton5.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton5.setAction(flexButtonCallback);
    flexButton5.setPosition(95, 135, 50, 50);
    add(flexButton5);

    flexButton2.setBoxWithBorderPosition(0, 0, 50, 50);
    flexButton2.setBorderSize(5);
    flexButton2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton2.setText(TypedText(T___SINGLEUSE_4W1B));
    flexButton2.setTextPosition(0, 0, 50, 50);
    flexButton2.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton2.setAction(flexButtonCallback);
    flexButton2.setPosition(95, 73, 50, 50);
    add(flexButton2);

    flexButton3.setBoxWithBorderPosition(0, 0, 50, 50);
    flexButton3.setBorderSize(5);
    flexButton3.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton3.setText(TypedText(T___SINGLEUSE_RES8));
    flexButton3.setTextPosition(0, 0, 50, 50);
    flexButton3.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton3.setAction(flexButtonCallback);
    flexButton3.setPosition(160, 73, 50, 50);
    add(flexButton3);

    buttonUnlock.setXY(0, 270);
    buttonUnlock.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_MEDIUM_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_MEDIUM_ROUNDED_PRESSED_ID));
    buttonUnlock.setLabelText(touchgfx::TypedText(T___SINGLEUSE_GDBH));
    buttonUnlock.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonUnlock.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonUnlock.setAction(buttonCallback);
    add(buttonUnlock);

    buttonRegister.setXY(0, 270);
    buttonRegister.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_MEDIUM_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_MEDIUM_ROUNDED_PRESSED_ID));
    buttonRegister.setLabelText(touchgfx::TypedText(T___SINGLEUSE_W6LV));
    buttonRegister.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonRegister.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonRegister.setVisible(false);
    buttonRegister.setAction(buttonCallback);
    add(buttonRegister);

    textArea1.setPosition(0, 15, 240, 45);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(252, 252, 247));
    textArea1.setLinespacing(0);
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_A610).getText());
    textArea1.setWildcard(textArea1Buffer);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ACRA));
    add(textArea1);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{

}

void Screen1ViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &flexButton1)
    {
        //Interaction1
        //When flexButton1 clicked call virtual function
        //Call function1
        function1();
    }
    if (&src == &flexButton2)
    {
        //Interaction2
        //When flexButton2 clicked call virtual function
        //Call function2
        function2();
    }
    if (&src == &flexButton3)
    {
        //Interaction3
        //When flexButton3 clicked call virtual function
        //Call function3
        function3();
    }
    if (&src == &flexButton4)
    {
        //Interaction4
        //When flexButton4 clicked call virtual function
        //Call function4
        function4();
    }
    if (&src == &flexButton5)
    {
        //Interaction5
        //When flexButton5 clicked call virtual function
        //Call function5
        function5();
    }
    if (&src == &flexButton6)
    {
        //Interaction6
        //When flexButton6 clicked call virtual function
        //Call function6
        function6();
    }
    if (&src == &flexButton7)
    {
        //Interaction7
        //When flexButton7 clicked call virtual function
        //Call function7
        function7();
    }
    if (&src == &flexButton8)
    {
        //Interaction8
        //When flexButton8 clicked call virtual function
        //Call function8
        function8();
    }
    if (&src == &flexButton9)
    {
        //Interaction9
        //When flexButton9 clicked call virtual function
        //Call function9
        function9();
    }
}

void Screen1ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonUnlock)
    {
        //Interaction10
        //When buttonUnlock clicked call virtual function
        //Call functionUnlock
        functionUnlock();
    }
    if (&src == &buttonRegister)
    {
        //Interaction14
        //When buttonRegister clicked call virtual function
        //Call functionRegister
        functionRegister();
    }
}

void Screen1ViewBase::handleTickEvent()
{
    //Interaction11
    //When every N tick call virtual function
    //Call function1Tick
    function1Tick();
}

void Screen1ViewBase::handleKeyEvent(uint8_t key)
{
    if(126 == key)
    {
        //Interaction13
        //When hardware button 126 clicked change screen to Screen2
        //Go to Screen2 with no screen transition
        application().gotoScreen2ScreenNoTransition();
    
    }
}
