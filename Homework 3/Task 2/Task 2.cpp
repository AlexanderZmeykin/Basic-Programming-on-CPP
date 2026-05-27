#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class Address
{
private:
    std::string city;
    std::string street;
    int house;
    int apartment;

public:
    Address(const std::string& city, const std::string& street, int house, int apartment)
        : city(city), street(street), house(house), apartment(apartment) {}

    std::string get_output_address() const
    {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
    }

    std::string get_output_city() const
    {
        return city;
    }
};

Address** address_reading(const std::string& filename, int& N)
{
    std::ifstream in(filename);
    if (!in.is_open())
    {
        std::cerr << "Ошибка открытия файла " << filename << std::endl;
        return nullptr;
    }
    else
    {
        std::cout << "Файл адресов был успешно открыт." << std::endl;
    }
    in >> N;
    in.ignore();

    Address** addresses = new Address * [N];

    for (int i = 0; i < N; ++i)
    {
        std::string city, street;
        int house, apartment;

        std::getline(in, city);
        std::getline(in, street);
        in >> house;
        in >> apartment;
        in.ignore();

        addresses[i] = new Address(city, street, house, apartment);
    }

    in.close();
    return addresses;
}

void address_writing(const std::string& filename, Address** addresses, int N)
{
    std::ofstream out(filename);
    if (!out.is_open())
    {
        std::cerr << "Ошибка создания файла " << filename << std::endl;
        return;
    }

    out << N << std::endl;
    for (int i = 0; i < N; ++i)
    {
        out << addresses[i]->get_output_address() << std::endl;
    }

    out.close();
    std::cout << "Файл был успешно открыт." << std::endl;
}


void address_sorting(Address** addresses, int N)
{
    std::stable_sort(addresses, addresses + N,
        [](const Address* a, const Address* b)
        {
            return a->get_output_city() < b->get_output_city();
        });
    std::cout << "Массив адресов был успешно отсортирован." << std::endl;
}

void delete_addresses(Address** addresses, int N)
{
    if (addresses == nullptr) return;
    for (int i = 0; i < N; ++i)
    {
        delete addresses[i];
    }
    delete[] addresses;
    std::cout << "Массив был успешно очищен." << std::endl;
}

int main()
{
    int N = 0;
    Address** addresses = address_reading("in.txt", N);

    if (addresses == nullptr)
    {
        return 1;
    }

    address_sorting(addresses, N);
    address_writing("out.txt", addresses, N);
    delete_addresses(addresses, N);

    return 0;
}