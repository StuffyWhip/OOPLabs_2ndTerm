#include "Container.h"
#include "Algorithm.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <limits>

struct Goods
{
    uint32_t m_id;
    std::string m_name;
    std::string m_manufacturer;
    std::string m_warehouse_address;
    double m_weight;

    Goods(uint32_t id,
        const std::string& name,
        const std::string& manufacturer,
        const std::string& warehouse_address,
        double weight) noexcept
        : m_id(id)
        , m_name(name)
        , m_manufacturer(manufacturer)
        , m_warehouse_address(warehouse_address)
        , m_weight(weight) {}

    Goods() noexcept :
        m_id(0)
        , m_name()
        , m_manufacturer()
        , m_warehouse_address()
        , m_weight(0.0) {}

    friend std::ostream& operator << (std::ostream& put, const Goods& goods) noexcept
    {
        if (!isNull(goods))
        {
            put << "Код товара: " << goods.m_id << std::endl;
            put << "Название: " << goods.m_name << std::endl;
            put << "Производитель: " << goods.m_manufacturer << std::endl;
            put << "Адрес склада: " << goods.m_warehouse_address << std::endl;
            put << "Вес: " << goods.m_weight << std::endl;
        }
        else
        {
            put << "Объект нулевой." << std::endl;
        }
        return put;
    }

    friend bool isNull(const Goods& goods)
    {
        return (goods.m_id == 0 && goods.m_name.empty()
            && goods.m_manufacturer.empty()
            && goods.m_warehouse_address.empty()
            && std::fabs(goods.m_weight) < std::numeric_limits<double>::epsilon());
    }
};

bool Manufacturer(const Goods& goods)
{
    static bool key = true;
    static std::string man;
    if (key)
    {
        man = goods.m_manufacturer;
        key = false;
    }
    return (man.compare(goods.m_manufacturer) == 0);
}

class OutputIterator
{
    std::ostream& os;

public:
    using iterator_category = std::output_iterator_tag;
    using value_type = void;
    using difference_type = void;
    using pointer = void;
    using reference = void;

    explicit OutputIterator(std::ostream& os) : os(os) {}

    template <typename T>
    OutputIterator& operator=(const T& value)
    {
        os << value << std::endl;
        return *this;
    }

    OutputIterator& operator*() { return *this; }
    OutputIterator& operator++() { return *this; }
    OutputIterator& operator++(int) { return *this; }
};


bool checkWeight(const Goods& goods, double minWeight, double maxWeight)
{
    return (goods.m_weight >= minWeight && goods.m_weight <= maxWeight);
}

int main()
{
    try
    {
        setlocale(0, "rus");
        auto print = [](const auto& x)
            {
                std::cout << x << " ";
            };

        std::cout << "----------Task 2----------" << std::endl;
        Vector<Goods> cont1{ {1,"Product1","Brand1","115253",123}, {2,"Product2","Brand2","123433",2},{ 3,"Product3", "Brand3", "94326", 210 } };
        forEach(cont1.begin(), cont1.End(), print);
        std::cout << "----------Task 3----------" << std::endl;
        Goods g2{ 4,"Product4","Brand4","4654574", 80 };
        Goods g3{ 5,"Product5","Brand5","143734", 450 };
        Goods g4{ 6,"Product6","Brand6","764444",220 };
        Goods g5{ 7,"Product7","Brand7","764224",330 };
        Goods g6{ 8,"Product8","Brand8","23435",50 };
        Goods g7{ 9,"Product9","Brand9","35",560 };
        Vector<Goods> cont2;
        cont2.push_back(g2);
        cont2.push_back(g3);
        cont2.push_back(g4);
        cont2.push_back(g5);
        cont2.Insert(cont2.End()--, g6);
        cont2.Insert(cont2.End()--, g7);
        forEach(cont2.begin(), cont2.End(), print);

        std::cout << "----------Task 4----------" << std::endl;
        cont1.Insert(cont1.End(), cont2.begin(), cont2.End());
        forEach(cont1.begin(), cont1.End(), print);

        std::cout << "----------Task 5----------" << std::endl;
        sort(cont1.begin(), cont1.End(), [](const Goods& g1, const Goods& g2) {
            return g1.m_name < g2.m_name;
            });

        forEach(cont1.begin(), cont1.End(), print);
        std::cout << "----------Task 6----------" << std::endl;
        Vector<Goods>::iterator res = findIf(cont1.begin(), cont1.End(), [](const auto& f)
            {
                return f.m_weight == 100;
            });

        if (res != cont1.End()) {
            print(*res);
        }
        else {
            std::cout << "Element with weight 100 not found." << std::endl;
        }
        std::cout << "----------Task 7----------" << std::endl;
        res->m_warehouse_address = "134256";
        forEach(cont1.begin(), cont1.End(), print);
        std::cout << "----------Task 8----------" << std::endl;
        Vector<Goods> cont_3(1, Goods());
        copyIf(cont1.begin(), cont1.End(), cont_3.begin(), Manufacturer);
        forEach(cont_3.begin(), cont_3.End(), print);
    }
    catch (const std::exception& err)
    {
        std::cout << err.what();
    }
    catch (...)
    {
        std::cout << "Error";
    }
    std::cout << "Доп. задание." << std::endl;
    std::cout << "Доп. задание." << std::endl;

    try
    {
        std::ofstream outputFile("output.txt");
        if (!outputFile)
        {
            std::cerr << "Failed to open the output file!" << std::endl;
            return 1;
        }

        std::vector<Goods> goodsList = {
            {1, "Product1", "Brand1", "Address1", 50},
            {2, "Product2", "Brand2", "Address2", 75},
            {3, "Product3", "Brand3", "Address3", 100},
            {4, "Product4", "Brand4", "Address4", 150},
            {5, "Product5", "Brand5", "Address5", 200}
        };

        double minWeight = 70;
        double maxWeight = 150;

        OutputIterator outputIterator(outputFile);

        copyIf(goodsList.begin(), goodsList.end(), outputIterator, [&](const Goods& goods) {
            return checkWeight(goods, minWeight, maxWeight);
            });

        std::cout << "Data has been written to the file 'output.txt'." << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown exception caught." << std::endl;
    }
    return 0;
}