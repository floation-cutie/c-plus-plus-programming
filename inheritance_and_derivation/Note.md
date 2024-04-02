派生类对基类 需要声明**继承方式**
1. 吸收已有类成员 继承已有类方法 包括`super`继承基类构造函数
2. 调整已有类成员 `override`
3. 添加新的成员

不同继承方式的影响：
1. 派生类**成员**对基类成员的访问权限
2. 派生类**对象**对基类成员的访问权限

公有继承：
派生类中的成员函数可以直接访问基类中的 public 和 protected 成员，但不能访问基类的 private 成员

对外部来说，通过派生类的对象只能访问基类的 public 成员

私有继承:
基类的 public/protected/private 成员在派生类中的访问属性都变成 private

保护继承:
基类的 public/protected成员在派生类中的访问属性都变成 protected

**类型兼容规则** 多态的体现 
单向兼容
1. 派生类的对象可以被赋值给基类对象
2. 派生类的对象可以用来初始化基类的引用
3. 指向基类的指针也可以用来指向派生类对象

多重继承 (如双继承)
* 派生类从多个基类派生
* 派生类继承多基类的所有属性和行为 即==成员== **并集**
* 多继承顺序由声明构造函数的参数列表顺序决定 

关于派生类的构造函数
核心: 子类无法继承父类的构造函数

通过`using`继承基类构造函数
`using Base::Base`

**在构造派生类构造函数时，基类构造函数将会被自动执行**
如果没有指定，会调用默认构造函数(即不带参数的构造函数)
也可以主动向基类传递参数
顺序为 基类 ---> 派生类 ---> 成员对象

析构函数的调用次数恰好相反

**同名隐藏规则**
如要通过派生类对象访问基类中被覆盖的同名成员，应使用基类名限定

二义性问题的解决

虚拟继承`class Programer : virtual public Human` 定义虚基类
在第一级继承时就要将共同基类设计为虚基类
建立对象时所指定的类称为最远派生类

**多态性**
发出同样的消息被不同类型的对象
接收时有可能导致完全不同的行为


implicit interface && explicit interface
隐式实现接口时，接口和类(实现接口的类)都可以访问类中的方法
显式接口只有通过接口来访问类中的方法

OOP 围绕着 **显式接口** && **运行时多态** 展开

virtual function作用 as Interface in Java
only have pure virtual function  -- > interface
don't have any pure virtual function aka can be instantiated
class that has at least one pure virtual function -- > abstract function

override virtual function is legal,but is ain't moral

Whether or not a destructor function is virtual indicates
whether a class is intended to be inherited from.

non-virtual function may cause memory leak
templates means static polymorphism,which can cause code bloat
if no common base can be defined, then use templates(runtime efficiency)

if compilt-time efficiency is most important, and u want to hide 
implements,use derived classes

继承和派生是同一概念 只是站的角度不同

菱形继承 < -- 被 虚继承 解决了间接基类数据冗余的问题    
**最远派生类会直接调用虚基类的构造函数**

多态指的是基类指针的运行时指向性多态
多态条件:
1. 必须存在继承关系
2. 继承关系中必须有同名的虚函数 并且他们是覆盖关系
3. 存在基类的指针，通过该指针调用虚函数

基类指针不能访问派生类的成员函数

使用`override`关键字 检查继承重写关系是否正确

虚析构函数 处理子类中存在指针成员变量时可能得内存泄漏

虚函数表 V-table
只有包含虚函数的类才会生成存储本类中虚函数地址的虚函数表
在代码的编译阶段时产生

**C++ 如何实现动态绑定? dynamic binding**
编译器在类中秘密增加一个vpointer (vptr) 用于指向对应的虚函数表

而vptr 只有在对象被构建，初始化构造函数的时候才被指向虚函数表

当子类无重写基类虚函数时，调用的是基类的函数