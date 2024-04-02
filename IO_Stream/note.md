本实验中的亮点在于
了解分析C++中的`pseudo-random number generation`

传统方法
```cpp
#include<iostream>

srand(time(nullptr));
std::cout << rand() << "\n"; 
```

适用性更强的engine generator
```cpp
#include<random>

std::random_device rd; //engine
std::unifrom_int_distribution<int> dist(1,1000);//distribution
dist(rd);
```