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

A const-correct version of the [Country](9dc97d3efa78ee00a012bd1b788abc7b5f29ab52) class.

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

## Constructors, destructors, copies

Let's add the following methods to the `Country` class:
- default constructor
- destructor
- copy constructor
- copy-assignment operator

Now the class should look something like:

```c++
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
```
Now let's play around with them!

### First
Having the following and the previous definition of `Country`:
```c++
void function_that_copies_country(Country country) {
    country.set_name("Denmark");
}

int main() {
    Country country{"Egypt", "Cairo", 120};
    function_that_copies_country(country);
    return 0;
}

```

<details>
<summary>:thinking: What will be the output?</summary>
<p>constructing country with params</p>
<p>copying country</p>
<p>destroying country</p>
<p>destroying country</p>
<br>
<p>Explanation: we construct `Egypt`, then copy it over at the function call.
The destructor then kicks in as both get out of the scope.</p>
</details>

### Second
Now let's have this:
```c++
/// Function that allows the inside of the function to modify the parameter, but avoids copying it
/// \param country
void function_that_allows_modifications(Country &country) {
    country.set_name("Argentina");
}


int main() {
    Country country{"Egypt", "Cairo", 120};
    function_that_allows_modifications(country);
    return 0;
}
```
<details>
<summary>:thinking: Will this work? What will be the output?</summary>
<p>constructing country with params</p>
<p>destroying country</p>
<br>
<p>Explanation: Yes, it will work, because `set_name` is not marked as const. Yes, it will correctly modify the country.</p>
</details>

### Now again
```c++
/// Function that allows the inside of the function to modify the parameter, but avoids copying it
/// \param country
void function_that_doesnt_allow_modifications(const Country &country) {
    country.set_name("Argentina"); // won't work
}

int main() {
    Country country{"Egypt", "Cairo", 120};
    function_that_doesnt_allow_modifications(country);
    return 0;
}
```
<details>
<summary>:thinking: Will this work? What will be the output?</summary>

<p>Explanation: Won't work. Country is declared as const, but `set_name` is not(and also it can't be since it does modify the object). A non-const qualified method can't be called on a const-qualified object.</p>
</details>
