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

A const-correct version of the [Country](https://github.com/imimali/oop-2023/commit/9dc97d3efa78ee00a012bd1b788abc7b5f29ab52) class.

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
constructing country with params<br>
copying country<br>
destroying country<br>
destroying country<br>
<br>
Explanation: we construct `Egypt`, then copy it over at the function call.
The destructor then kicks in as both get out of the scope.<br>
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
constructing country with params<br>
destroying country<br>
<br>
Explanation: Yes, it will work, because `set_name` is not marked as const. Yes, it will correctly modify the country.<br>
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

Explanation: Won't work. Country is declared as const, but `set_name` is not(and also it can't be since it does modify the object). A non-const qualified method can't be called on a const-qualified object.<br>
</details>

### Let's try vectors now
Let's have some [more countries](https://www.youtube.com/watch?v=rvrZJ5C_Nwg&t=264s)!
```c++
int main() {
    Country country{"Cuba", "Havana", 123};
    Country country1{"Indonesia", "Djakarta", 345};
    Country country2{"Jamaica", "Kingston", 30};
    std::vector<Country> countries;
    countries.push_back(country);
    countries.push_back(country1);
    countries.push_back(country2);
    return 0;
}
```
<details>
<summary>:thinking: Will this work? What will be the output?</summary>

constructing country with params<br>
constructing country with params<br>
constructing country with params<br>
copying country<br>
copying country<br>
copying country<br>
destroying country<br>
copying country<br>
copying country<br>
copying country<br>
destroying country<br>
destroying country<br>
destroying country<br>
destroying country<br>
destroying country<br>
destroying country<br>
destroying country<br>
destroying country<br>

<br>
<b>So what happened here exactly?</b>
We create three countries, `push-back` copies them over, get three copies, so far so good. But where does the rest come from?<br>
Explanation: the std:vector is a dynamic vector. It resizes, and while moving the elements, it copies them over and destroys the old ones.<br>
Try adding the following line after `countries` is declared and see the output:<br>
<i>countries.reserve(3);</i>
</details>

### But wait, there's more
```c++
int main() {
    Country country{"Cuba", "Havana", 123};
    Country country1{"Indonesia", "Djakarta", 345};
    Country country2{"Jamaica", "Kingston", 30};
    std::vector<Country> countries;
    countries.reserve(3);
    countries.push_back(country);
    countries.push_back(country1);
    countries.push_back(country2);

    for(Country c:countries){
        // do something
    }
    return 0;
}
```
<details>
<summary>:thinking: What will be the output?</summary>
constructing country with params<br>
constructing country with params<br>
constructing country with params<br>
copying country<br>
copying country<br>
copying country<br>
copying country<br>
destroying country<br>
copying country<br>
destroying country<br>
copying country<br>
destroying country<br>
destroying country<br>
destroying country<br>
destroying country<br>
destroying country<br>
destroying country<br>
destroying country<br>
<br>
Explanation: the for loop copies every country in the local variable, which as soon as they get out of the scope, get deallocated.<br>
Try modifying the loop to something like<br>
<i>for(const Country& c:countries)</i>
</details>

### Copy constructor
```c++
int main() {
    Country country{"Cuba", "Havana", 123};
    Country country1=country;
    return 0;
}
```
<details>
<summary>:thinking: What will be the output?</summary>
constructing country with params<br>
copying country<br>
destroying country<br>
destroying country<br>
<br>
Explanation: `country1` is declared as a copy of `country`, so it is initialized via the copy constructor<br>
</details>

### Copy assigment
```c++
int main() {
    Country country{"Cuba", "Havana", 123};
    Country country1;
    country1=country;
    return 0;
}
```
<details>
<summary>:thinking: What will be the output?</summary>
constructing country with params<br>
default-constructing country<br>
copy-assigning country<br>
destroying country<br>
destroying country<br>
<br>
Explanation: `country1` is initialized with the default constructor and only later reassigned, so it won't be the copy constructor,
but the copy assignment operator that kicks in.<br>
</details>

### Last, but not least
```c++
int main() {
    std::vector<Country> countries(5);
    return 0;
}
```
<details>
<summary>:thinking: What will be the output?</summary>

default-constructing country<br>
default-constructing country<br>
default-constructing country<br>
default-constructing country<br>
default-constructing country<br>
destroying country<br>
destroying country<br>
destroying country<br>
destroying country<br>
destroying country<br>
<br>
Explanation: When we initialize a vector like this, the underlying structure will actually initialize objects there(unlike `reserve`, which only allocates the necessary space. Therefore, we end up with 5 objects in the underlying vector, that also get deallocated in the end.<br>
</details>