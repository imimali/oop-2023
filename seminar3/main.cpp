#include <iostream>
#include <string>

class Country {
private:
    std::string name;
    std::string capital;
    int population;
public:

    Country(std::string name, std::string capital, int population) {
        this->name = name;
        this->population = population;
        this->capital = capital;

    }

    std::string get_name() {
        return this->name;
    }

    std::string get_capital() {
        return this->capital;
    }

    int get_population() {
        return this->population;
    }

    std::string to_string() {
        return "Country {name = " + this->name + ", capital=" + this->capital + ", population=" +
               std::to_string(this->population) + "}";
    }

};


int main() {
    Country country{"Cuba", "Havana", 11};
    std::cout << country.to_string() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}