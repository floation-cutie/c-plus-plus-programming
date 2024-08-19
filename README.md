# c-plus-plus-programming
**homework of c++ in BUPT**

MakeFile适用于Windows下的PowerShell
建议实际开发使用linux环境

Note:使用常量对象时，只能调用其常成员函数 

对C++ 的 M_PI undefined 宏的分析

参考[博客](https://init.blog/1549/)
> 分析预编译器的引用过程
> 
> 先去寻找定义这个 M_PI 宏的文件, 从 cmath 出发, 
> 
> 到cstdlib 再到 math.h
> 
> 找到了 M_PI 宏定义和条件编译 #define _USE_MATH_DEFINES 
> 
> 而 iostream在逐级引用扩展文件的过程中 扩展到了cmath
> 
> 然而此时这个时候我们还没有定义 _USE_MATH_DEFINES 
> 
> 但是在预编译器真的定义宏之后，之前的文件已经加载过了，不再被使用


尽量要通过引用捕获异常
