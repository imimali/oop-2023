#include <iostream>
#include <string>
#include <vector>

using std::string;

class Country{
private:
    string name;
    string capital;
    int population;
public:
    Country(){
        std::cout<<"default constructing country"<<std::endl;
    }
    Country(const string &name, const string &capital, int population) {
        std::cout<<"constructing country"<<std::endl;
        this->capital = capital;
        this->name = name;
        this->population = population;
    }

    Country &operator=(const Country &other) {
        std::cout << "copy assignment operator" << std::endl;
        return *this;
    }

    Country(const Country &other) {

        this->name = other.name;
        this->capital = other.capital;
        this->population = other.population;
        std::cout << "copy constructing" << std::endl;
    }

    ~Country(){
        std::cout << "destructing" << std::endl;
    }

    const string &get_name() const {
        return this->name;
    }

    const string &get_capital() const {
        return this->capital;
    }

    int get_population() const {
        return this->population;
    }

    string to_string() const {
        return "Country {name = " + this->name + ", capital= " + this->capital + ", population= " +
               std::to_string(this->population) + "}";
    }

    void set_name(const string &new_name) {
        this->name = new_name;
    }
};

void f(const Country &c) {
    c.get_name();
}

int main() {
//    {
//        Country country{"Russia", "Moscow", 150};
//        Country country1{"Bolivia", "La Paz", 12};
//        Country country2{"Columbia", "Havana", 88};
//        std::vector<Country> countries(10);
////        countries.push_back(country);
////        countries.push_back(country1);
////        countries.push_back(country2);
//        std::cout << "done creating" << std::endl;
//        std::cout << country.to_string() << std::endl;
////        Country* country3=new Country{"Namibia","asdfds",123};
////        delete country3;
//    }
    Country country;
    Country country1=country;

    country=country1;
    std::cout<<"done "<<std::endl;
    return 0;
}
