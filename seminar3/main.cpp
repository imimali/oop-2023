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
        std::cout << "copy-constructing country" << std::endl;
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

    std::string to_string() {// no const reference!
        return "Country {name = " + this->name + ", capital=" + this->capital + ", population=" +
               std::to_string(this->population) + "}";
    }

    void set_name(const std::string &new_name) {//can't mark as const
        this->name = new_name;
    }

};

void function_that_copies_country(Country country) {
    country.set_name("Denmark");
}

/// Function that allows the inside of the function to modify the parameter, but avoids copying it
/// \param country
void function_that_allows_modifications(Country &country) {
    country.set_name("Argentina");
}

/// Function that allows the inside of the function to modify the parameter, but avoids copying it
/// \param country
void function_that_doesnt_allow_modifications(const Country &country) {
    //country.set_name("Argentina"); // won't work
}


int main() {
    Country country{"Egypt", "Cairo", 120};
    function_that_copies_country(country);
    return 0;
}
