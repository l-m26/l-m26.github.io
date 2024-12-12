#include "bee.h"
#include <string.h>

#define MAX_unit_num 200 //???大乐谱数???
int tone[3][8];
//初始化高中低???
void tone_init(void){
	tone[1][0] = 0;	//不执???
	tone[1][1] = 191;
	tone[1][2] = 170;
	tone[1][3] = 151;
	tone[1][4] = 143;
	tone[1][5] = 127;
	tone[1][6] = 113;
	tone[1][7] = 101;
    // 低音 (Low)
    for (int i = 0; i < 8; i++) {
        tone[0][i] = tone[1][i] * 2; // 只是???个近似的值，实际值可能不???
    }
 
    // 高音 (High)
    for (int i = 0; i < 8; i++) {
        tone[2][i] = tone[1][i] / 2; // 只是???个近似的值，实际值可能不???
    }
}
 
 

//创建结构体保存乐???
struct music_unit{
	char name[50];		//乐谱名称
	int unit[MAX_unit_num];		//发什么音
	int unit_HL[MAX_unit_num];	//发高音或者其???
	int time[MAX_unit_num];		//发音时间
	//int time_4[MAX_unit_num];	//判断是否???1/4???
	int num;			//记录有多少个
}music[25];
 
//创建乐谱 返回有多少首音乐
int music_init(void){
	int cnt = 0;
	//第一首音??? 生日快乐
	strcpy(music[0].name, "生日快乐"); 				// 使用strcpy复制字符??? 给音乐命???
	int music0_unit[29] = {0,0, 5,5,6,5,1,7, 5,5,6,5,2,1,
								5,5,6,3,1,7, 6,4,4,3,1,2,1,
								0,0};		//基础乐谱
	int music0_time[29] = {1,1, 1,1,2,2,2,3, 1,1,2,2,2,3,
								2,2,2,2,2,2, 2,2,2,2,2,2,3,
								1,1};		//乐谱节拍
	music[0].num = 29;										//乐谱总数
	int music0_unit_HL[29] = {1,1,
								0,0,0,0,1,0, 0,0,0,0,1,1,
								0,0,1,1,1,0, 0,1,1,1,1,1,1,
								1,1}; 	//乐谱全为中音
 
	//第二首音??? ???闪一闪亮晶晶
	cnt++;
	strcpy(music[1].name, "???闪一闪亮晶晶"); 					// 使用strcpy复制字符??? 给音乐命???
	int music1_unit[44] = {0,
						   1,1,5,5,6,6,5, 4,4,3,3,2,2,1,
						   5,5,4,4,3,3,2, 5,5,4,4,3,3,2,
						   1,1,5,5,6,6,5, 4,4,3,3,2,2,1,
						   0};		//基础乐谱
	int music1_time[44] = {2,
						   2,2,2,2,2,2,3, 2,2,2,2,2,2,3,
						   2,2,2,2,2,2,3, 2,2,2,2,2,2,3,
						   2,2,2,2,2,2,3, 2,2,2,2,2,2,3,
						   2};		//乐谱节拍
	int music1_unit_HL[44] =
						  {1,
						   1,1,1,1,1,1,1, 1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1, 1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1, 1,1,1,1,1,1,1,
						   1}; 		//乐谱全为中音
	music[1].num = 44;											//乐谱总数
 
 
 
	//第三首音??? 两只老虎
	cnt++;
	strcpy(music[2].name, "两只老虎"); 					// 使用strcpy复制字符??? 给音乐命???
	int music2_unit[38] = {0,
						   1,2,3,1, 1,2,3,1, 3,4,5,5, 3,4,5,5,
						   5,6,5,4, 3,1,5,6, 5,4,3,1, 1,5,1,1,
						   1,5,1,1, 0};		//基础乐谱
	int music2_time[38] = {2,
						   1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
						   0,0,0,0, 1,1,0,0, 0,0,1,1, 1,1,1,2,
						   1,1,1,2, 2};		//乐谱节拍
	int music2_unit_HL[38] =
						  {1,
					       1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
						   1,1,1,1, 1,1,1,1, 1,1,1,1, 1,0,1,1,
						   1,0,1,1, 1}; 		//乐谱???   中音
	music[2].num = 38;											//乐谱总数
 
 
	//第四首音??? 青花瓷片???
	cnt++;
	strcpy(music[3].name, "青花瓷片选"); 					// 使用strcpy复制字符??? 给音乐命???
	int music3_unit[100] = {0,0,0,0, 0,5,5,3, 2,3,6,2, 3,5,3,2, 2,5,5,3,
						    2,3,5,2, 3,5,2,1, 1,1,2,3, 5,6,5,4, 5,3,3,2,
						    2,2,1,2, 1,1,2,1, 2,3,5,3, 3,3,5,5, 3,2,3,6,
						    2,3,5,3, 2,2,5,5, 3,2,3,5, 2,3,5,2, 1,1,1,2,
						    3,5,6,5, 4,5,3,3, 2,2,5,3, 2,2,2,1, 1,0,0,0};		//基础乐谱
 
	int music3_time[100] = {0,0,0,0, 0,0,0,0, 0,0,1,0, 0,0,0,2, 0,0,0,0,
							0,0,1,0, 0,0,0,2, 0,0,0,0, 0,0,0,0, 0,0,0,0,
							2,0,0,0, 0,0,0,0, 0,1,0,0, 2,0,0,0, 0,0,0,1,
							0,0,0,0, 2,0,0,0, 0,0,0,1, 0,0,0,0, 2,0,0,0,
							0,0,0,0, 0,0,0,0, 0,2,0,1, 0,0,0,1, 2,1,1,1};		//乐谱节拍
 
	for(int i =0;i<100;i++)
		music3_time[i] = music3_time[i]+1;
 
	int music3_unit_HL[100] =
						  { 1,1,1,1, 1,1,1,1, 1,1,0,1, 1,1,1,1, 1,1,1,1,
							1,1,0,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
							1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,0,
							1,1,1,1, 1,1,1,1, 1,1,1,0, 1,1,1,1, 1,1,1,1,
							1,1,1,1, 1,1,1,1, 1,1,0,1, 1,1,1,1, 1,1,1,1}; 		//乐谱???   中音
	music[3].num = 100;											//乐谱总数
 
 
 
 
	for (int i = 0; i < MAX_unit_num; i++) {
		//将乐谱保存进结构???
		if(i<music[0].num){//确保数据正确
			music[0].unit[i] =music0_unit[i];
			music[0].unit_HL[i] =music0_unit_HL[i];
			music[0].time[i] =music0_time[i];
		}
 
 
		//将乐谱保存进结构???
		if(i<music[1].num){//确保数据正确
			music[1].unit[i] =music1_unit[i];
			music[1].unit_HL[i] =music1_unit_HL[i];
			music[1].time[i] =music1_time[i];
		}
 
		//将乐谱保存进结构???
		if(i<music[2].num){//确保数据正确
			music[2].unit[i] =music2_unit[i];
			music[2].unit_HL[i] =music2_unit_HL[i];
			music[2].time[i] =music2_time[i];
		}
 
 
		//将乐谱保存进结构???
		if(i<music[3].num){//确保数据正确
			music[3].unit[i] =music3_unit[i];
			music[3].unit_HL[i] =music3_unit_HL[i];
			music[3].time[i] =music3_time[i];
		}
	}
 
 
	return cnt;
}
 
 
 
 
 
//播放??? N首音??? 音量??? X 0 - 100
void play_music(int n, int x){
	static int ni = 0; 		//用于判断 是否换了音乐
	static int cnt = 0;		//记录播放到哪?????? 音节
	
 
	//
	int value = tone[music[n].unit_HL[cnt]][music[n].unit[cnt]];	//获取频率
	if(flag == 1){	//接受到一个音节结???
		flag = 0;	//复位
		Beat_num = music[n].time[cnt]; 				//这个音需要多少个半拍
 
		if(music[n].time[cnt] == 0){//如果??? 1/4???
			Beat_speed_n = Beat_speed /2;
		}
		else{//如果没有1/4???
			Beat_speed_n = Beat_speed;
		}
 
		//if(value != 0)//如果有频率???执行，没有者只更新 时间???
		__HAL_TIM_SET_AUTORELOAD(&htim12,value);		//自动加载频率???
 
		cnt ++; 	//可进行下???次音???
		if(cnt >= music[n].num){ //如果???个音节播放完???
			cnt = 0;//重新播放
			//__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,0);//设置音量
			//HAL_Delay(500);//
		}
	}
	//__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,x * (value/100));//设置音量
	__HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_2,(value/20)*x);//设置音量
}






























