外部中断流水灯，是通过按键的中断方式来控制流水灯的行为，


#define IS1 1
#define IS2 1
来进行按键中断的选择，define为1时，将启用对应按键的函数，并在按键初始化时初始
化选中的按键。
intKeyInit();             
在使用按键时，应先对按键进行初始化。
void setIntKey1Fun(void (*fun)(void));
设置按键的回调函数,用于在按键按下时，产生中断的回调函数。