#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Country {
private:
    std::string name;
    std::string capital;
    int population;
public:

    Country(const std::string &name, const std::string &capital, int population) {
        std::cout << "constructing country with params" << std::endl;
        this->name = name;
        this->population = population;
        this->capital = capital;

    }

    /// default constructor - has no arguments
    Country() {
        this->name = "";
        this->population = 0;
        this->capital = "";
        std::cout << "default-constructing country" << std::endl;
    }

    /// destructor - also has no arguments
    ~Country() {
        std::cout << "destroying country" << std::endl;
    }

    /// Copy constructor - invoked when constructing an object from another
    /// \param country
    Country(const Country &country) {
        this->name = country.name;
        this->population = country.population;
        this->capital = country.capital;
        std::cout << "copying country" << std::endl;
    }

    /// Copy-assignment operator - invoked when assigning one object to another
    /// \param other
    /// \return
    Country &operator=(const Country &other) {
        this->name = other.name;
        this->capital = other.capital;
        this->population = other.population;
        std::cout << "copy-assigning country" << std::endl;
        return *this;
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

    std::string to_string() const {// no const reference!
        return "Country {name = " + this->name + ", capital=" + this->capital + ", population=" +
               std::to_string(this->population) + "}";
    }

    void set_name(const std::string &new_name) {//can't mark as const
        this->name = new_name;
    }

};


int main() {
    std::vector<Country> countries;
    countries.emplace_back("USA", "Washington", 300);
    countries.emplace_back("China", "Beijing", 1000);
    countries.emplace_back("Russia", "Moscow", 150);
    countries.emplace_back("India", "Mumbai", 1000);
    std::vector<Country> filtered;
    int min_population = 500;

    std::copy_if(countries.begin(), countries.end(),
                 std::back_inserter(filtered),
                 [min_population](const Country &c) {
                     return c.get_population() > min_population;
                 }
    );

    std::sort(countries.begin(), countries.end(),
              [](const Country &c1, const Country &c2) {
                  return c1.get_population() > c2.get_population();
              });

    std::cout << "Filtered:" << std::endl;
    for (const Country &c: filtered) {
        std::cout << c.to_string() << std::endl;
    }

    std::cout << "All sorted:" << std::endl;
    for (const Country &c: countries) {
        std::cout << c.to_string() << std::endl;
    }
    return 0;
}
