#include <iostream>
#include "memory"
#include "vector"

//template <typename T1>
//T1 TemplateSum(T1 t1){
//    return t1;
//}
//
//template <typename T1, typename... T>
//T1 TemplateSum(T1 t1, T... t){
//    return t1 + TemplateSum(t...); // TemplateSum(t2,t3...)
//}

//class Person {
//private:
//    std::string mName;
//    int mRokNar;
//
//public:
//    Person(const std::string& name, int rokNarozeni) : mName(name), mRokNar(rokNarozeni){
//        std::cout << "Vytvarim "<< name << " (" << rokNarozeni << ")" << std::endl;
//    }
//
//    Person (const std::string& name, int rokNarozeni, int gender)
//        : mName(name), mRokNar(rokNarozeni){
//        //
//    }

//    Person(Person&& l) : mName(l.mName), mRokNar(l.mRokNar) {
//        std::cout << "Move asign "<< mName << std::endl;
//    }
//    Person& operator = (const Person&& l)
//        :  mName = l.mName; mRokNar = l.mRokNar{
//        std::cout << "Move asign "<< mName << std::endl;
//    }

//    Person(const Person& l) = delete;
//    Person& operator= (const Person& l) = delete;
//};

//template<typename T, typename... TArgs>
//std::unique_ptr<T> Make(TArgs&&... args){
//    return std::unique_ptr<T>(new T(std::forward<TArgs>(args) ...));
//}

template<typename... TArgs>
int TemplateSum(TArgs... args){
//    return ((args+5) + ...);
    return (... - args);
}

/*
 * 1) any_of_contains   - variadicka funkce - prebira sadu kontejneru jako parametry (varia)
 *                      - zda nejaky z kontejneru obsahuje zadany prvek
 *
 *                      any_of_constains (5, my_vector, my_list, my_list2);
 *
 * 2) quoted_print      - variadicka funkce - prebira libovolne paramtery kdete jdou vypsat na proud <<
 *                      - vypise v uvozovkach carkou oddelene paramerty na standarti vystup
 *
 *                      quoted_print("hello", "there", 42, 88.0);
 *
 *                      "hello", "there", "42", "88.0"
 * */
int main() {
    std::cout << "Hello, World!" << std::endl;

    int c = TemplateSum(1,2,3,4,5);
    int x = TemplateSum(1,2,3,4,c,6,7,8);

    int p = TemplateSum(1,2,3,4,5);
    std::cout << p << std::endl;

    // int a = Template(4);
    // int a = 4;

//    auto person = Make<Person>("Honza", 1990);
//    auto person2 = std::make_unique<Person>("Honza", 1990);

//    std::vector<Person> lidi;
//
//    lidi.push_back({"Antonin", 1980});
//    lidi.emplace_back("Jiri", 1850);

    std::tuple<std::string, int, int> t1("aaa",5,6);

    auto s1 = std::get<0>(t1);
    auto b = std::get<1>(t1);

    std::string s;
    int i;
    int j;

    std::tie(s,i,std::ignore) = t1;

    std::cout << s << std::endl;
    std::cout << i << std::endl;
    return EXIT_SUCCESS;
}
