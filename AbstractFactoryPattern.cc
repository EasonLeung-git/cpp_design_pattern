// 抽象工厂类
// 创建产品、工厂抽象类
// 创建具体产品（继承于抽象产品类）、具体工厂类（继承于抽象工厂类）
// 在具体工厂类中创建生产产品类方法

#include <iostream>

// 抽象产品类
class AbstractProduct
{
public:
    AbstractProduct()  = default;
    virtual ~AbstractProduct() = default;
    
    virtual void do_something() = 0;
};

// 具体产品，继承于抽象产品类
class ProductA
    : public AbstractProduct
{
public:
    ProductA()  = default;
    virtual ~ProductA() = default;

    inline virtual void do_something()
    {
        std::cout << "ProductA\n";
    }
};

// 具体产品，继承于抽象产品类
class ProductB
    : public AbstractProduct
{
public:
    ProductB()  = default;
    virtual ~ProductB() = default;

    inline virtual void do_something()
    {
        std::cout << "ProductB\n";
    }
};
// ========================== /
/// 抽象工厂类
// ========================== /
class AbstractFactory
{
public:
    AbstractFactory() = default;
    virtual ~AbstractFactory() = default;
    
    // 生产产品纯虚函数
    virtual AbstractProduct* CreateProductA() = 0;
    virtual AbstractProduct* CreateProductB() = 0;
};

// 具体产品类
class ConcreteFactory
    : public AbstractFactory
{
public:
    ConcreteFactory()  = default;
    ~ConcreteFactory() = default;
    
    inline AbstractProduct* CreateProductA()
    {
        return new ProductA();
    }
    inline AbstractProduct* CreateProductB()
    {
        return new ProductB();
    }
};


int main()
{
    AbstractFactory *factory = new ConcreteFactory();
    AbstractProduct *product_a = factory->CreateProductA();
    AbstractProduct *product_b = factory->CreateProductB();

    product_a->do_something();
    product_b->do_something();

    delete factory;
    factory = nullptr;
    delete product_a;
    product_a = nullptr;
    delete product_b;
    product_b = nullptr;

    return 0;
}
