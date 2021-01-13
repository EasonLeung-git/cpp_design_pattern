// 单例模式
#include <iostream>
#include <thread>
#include <iomanip>

///////////////////
// 懒汉式单例模式 //
///////////////////
class SingletonPattern
{
public:
    ~SingletonPattern() = default;
private:
    // 构造函数私有化
    SingletonPattern() = default;
    // 静态成员只能静态方法来使用
    static SingletonPattern *m_pInstance;
    
public:
    static SingletonPattern* getInstance()
    {
        if (m_pInstance == nullptr)
        {
            m_pInstance = new SingletonPattern;
        }
        return m_pInstance;
    }
    // free
    static void deleteInstance()
    {
        delete m_pInstance;
        m_pInstance = nullptr;
    }

    void doSomething()
    {
        std::cout << "SingletonPattern::doSomething()\n";
    }
};
// 初始化静态成员变量
SingletonPattern* SingletonPattern::m_pInstance = nullptr;

/////////////////////
// 线程安全单例模式 //
//    饿汉模式     //
/////////////////////
class SingletonPatternThreadSafety
{
private:
    // 构造、析构、拷贝构造私有化，禁止外部构造和析构
    SingletonPatternThreadSafety()  = default;
    ~SingletonPatternThreadSafety() = default;
    // 将其拷贝构造和赋值构造成为私有函数, 禁止外部拷贝和赋值
    SingletonPatternThreadSafety(SingletonPattern &);
    // 重载运算符 =，私有化
    SingletonPatternThreadSafety& operator = (const SingletonPatternThreadSafety &);

public:
    static SingletonPatternThreadSafety* getInstance()
    {
        static SingletonPatternThreadSafety *instance;
        return instance;
    }

    void doSomething()
    {
        std::cout << "SingletonPatternThreadSafety::doSomething()\n";
    }
};

int main()
{
    // 懒汉模式
    {
        auto *instance = SingletonPattern::getInstance();
        instance->doSomething();
        // SingletonPattern::deleteInstance();
        instance->deleteInstance();
    }

    // 饿汉模式
    {
        auto *instance = SingletonPatternThreadSafety::getInstance();
        instance->doSomething();
        // 构造函数私有化，无法 delete
        // delete instance;
        instance = nullptr;
    }

    return 0;
}
