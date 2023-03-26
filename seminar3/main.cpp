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
    int k = 10, k1 = 11;
    const int *p = &k; // pointer to int that is constant
    int const *p1 = &k;

    p = &k1;//works
    // *p+=1; // doesn't work

    p1 = &k1;//works
    // *p1 += 1;// doesn't work

    // int* const p2; // has to be initialized, doesn't work
    int *const p2 = &k;
    // p2=&k1; // doesn't work
    const int *const p3 = &k;//const pointer to const int
    // p3=&k1; // doesn't work
    // *p3+=1; // doesn't work
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
