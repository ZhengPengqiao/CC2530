  #define TIME1 1
  #define TIME3 0
  #define TIME4 0


选择是能哪一个中断定时器


设置timex中断函数
 extern void setINTTimexFun(int (*inTx_function)());
设置TxCC的值，在非自由模式时使用
extern void setTxCCxValue(unsigned short val, ENUM_TIME1_CHANNAL channal);
根据参数初始化定时器
extern void initTimex(ENUM_TIME1_CLKDIV time_clkdiv,ENUM_TIME1_MODE time_mode, \
  ENUM_TIME1_CHANNAL channal);