#include <iostream>
#include <string>

class Country {
private:
    std::string name;
    std::string capital;
    int population;
public:

    Country(const std::string &name, const std::string &capital, int population) {
        this->name = name;
        this->population = population;
        this->capital = capital;

    }

    const std::string &get_name() const {
        return this->name;
    }

    const std::string &get_capital() const {
        return this->capital;
    }

    int get_population() const {
        return this->population;
    }

    std::string to_string() {// no const reference!
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
