#include <iostream>
#include <sstream>
#include <string>

int main()
{
    // 创建一个字符串，包含数值和文本
    std::string input = "12345 This is a test 67890";

    // 创建一个 stringstream 对象
    std::stringstream ss(input);

    // 用于存储数值和文本的变量
    int number;
    std::string text;

    // 从 stringstream 中读取数值
    ss >> number;
    std::cout << "Number: " << number << std::endl;

    // 读取直到遇到换行符的文本
    std::getline(ss, text);
    std::cout << "Text: " << text << std::endl;

    // 再次从 stringstream 中读取数值
    std::cout << "The current ss is " << ss.str() << std::endl;
    ss >> number;
    std::cout << "Number: " << number << std::endl;

    // 由于已经到达 stringstream 的末尾，尝试读取文本将失败
    // 因此，我们需要先清除 stringstream 的状态
    ss.clear();

    // 将 stringstream 的内容重新设置为原始输入
    ss.str(input);

    // 跳过前五个字符（数值）
    ss.seekg(5, std::ios::beg);

    // 读取剩余的文本
    std::getline(ss, text);
    std::cout << "Remaining Text: " << text << std::endl;

    return 0;
}
