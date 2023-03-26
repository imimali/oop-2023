# Seminar 3

A basic example:
```c++
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
```

:bulb: Question: How can we reduce the number of copying strings?

## Const correctness

A const-correct version of the [Country](14805ccd9707b3be8b3d4a7dd314a9dce05820db) class.

### Const ninja :ninja:

```c++
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
```
