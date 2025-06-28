#include <gui/screen1_screen/Screen1View.hpp>
#include "cmsis_os.h"
#include "stm32f4xx_hal.h"

#define FLASH_USER_START_ADDR   0x081E0000  // Sector
#define FLASH_USER_END_ADDR     0x081FFFFF  // Cuối sector 11

extern osMessageQueueId_t Queue1Handle;

void Flash_Append_Uint32(uint32_t data) {
    HAL_FLASH_Unlock();

    uint32_t address = FLASH_USER_START_ADDR;

    // Tìm vị trí chưa ghi (0xFFFFFFFF)
    while (address < FLASH_USER_END_ADDR) {
        uint32_t value = *(uint32_t*)address;
        if (value == 0xFFFFFFFF) {
            // Ghi tại vị trí này
            HAL_FLASH_Program(TYPEPROGRAM_WORD, address, data);
            break;
        }
        address += 4;
    }

    HAL_FLASH_Lock();
}

uint32_t Flash_Read_All_Uint32(uint32_t* buffer, uint32_t max_length) {
    uint32_t address = FLASH_USER_START_ADDR;
    uint32_t count = 0;

    while (address < FLASH_USER_END_ADDR && count < max_length) {
        uint32_t value = *(uint32_t*)address;
        if (value == 0xFFFFFFFF) {
            break;  // Dữ liệu kết thúc
        }
        buffer[count++] = value;
        address += 4;
    }

    return count; // trả về số phần tử đã đọc
}

void Flash_Clear_Log() {
    HAL_FLASH_Unlock();
    FLASH_Erase_Sector(FLASH_SECTOR_23, VOLTAGE_RANGE_3);
    HAL_FLASH_Lock();
}

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
//    Flash_Clear_Log();
    isUnlock = 1;
    password = 0;
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::function1Tick(){
	Screen1ViewBase::function1Tick();
	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", password);
	textArea1.invalidate();
	uint8_t res;
		if (osMessageQueueGetCount(Queue1Handle) > 0){
			osMessageQueueGet(Queue1Handle, &res, NULL, osWaitForever);
			if(res == 'C'){
				isUnlock = 0;
			}
		}
	if(isUnlock == 1){
		buttonUnlock.setVisible(true);
		buttonRegister.setVisible(false);
	}else{
		buttonUnlock.setVisible(false);
		buttonRegister.setVisible(true);
	}
	invalidate();
}


void Screen1View::functionUnlock(){
	uint32_t logs[128] = {0};
	uint32_t count = Flash_Read_All_Uint32(logs, 128);
	for(uint32_t i = 0; i < count; i++){
		if(password == logs[i]){
			password = 0;
			isUnlock = 1;
			application().gotoScreen2ScreenNoTransition();
		}
	}
	password = 0;
}

void Screen1View::functionRegister(){
		uint32_t logs[128] = {0};
		uint32_t count = Flash_Read_All_Uint32(logs, 128);
		int flag = 0;
		for(uint32_t i = 0; i < count; i++){
			if(password == logs[i]){
				flag = 1;
				password = 0;
				break;
			}
		}
		if(flag == 0){
			Flash_Append_Uint32(password);
			isUnlock = 1;
			password = 0;
			application().gotoScreen2ScreenNoTransition();
		}
}

void Screen1View::function1(){
	if(password < max){
		password = password*10 + 1;
	}
}

void Screen1View::function2(){
	if(password < max){
		password = password*10 + 2;
	}
}
void Screen1View::function3(){
	if(password < max){
		password = password*10 + 3;
	}
}
void Screen1View::function4(){
	if(password < max){
		password = password*10 + 4;
	}
}
void Screen1View::function5(){
	if(password < max){
		password = password*10 + 5;
	}
}
void Screen1View::function6(){
	if(password < max){
		password = password*10 + 6;
	}
}
void Screen1View::function7(){
	if(password < max){
		password = password*10 + 7;
	}
}
void Screen1View::function8(){
	if(password < max){
		password = password*10 + 8;
	}
}
void Screen1View::function9(){
	if(password < max){
		password = password*10 + 9;
	}
}


