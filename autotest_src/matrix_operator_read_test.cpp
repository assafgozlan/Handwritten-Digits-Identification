//
// Created by User on 7/20/2020.
//

#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <functional>
#include <type_traits>

template<typename T>
struct function_traits;

template<class F>
struct function_traits;

// function pointer
template<class R, class... Args>
struct function_traits<R(*)(Args...)> : public function_traits<R(Args...)>
{};

template<class R, class... Args>
struct function_traits<R(Args...)>
{
    using return_type = R;

    static constexpr std::size_t arity = sizeof...(Args);

    template <std::size_t N>
    struct argument
    {
        static_assert(N < arity, "error: invalid parameter index.");
        using type = typename std::tuple_element<N,std::tuple<Args...>>::type;
    };
};

// member function pointer
template<class C, class R, class... Args>
struct function_traits<R(C::*)(Args...)> : public function_traits<R(C&,Args...)>
{};

// const member function pointer
template<class C, class R, class... Args>
struct function_traits<R(C::*)(Args...) const> : public function_traits<R(C&,Args...)>
{};

// member object pointer
template<class C, class R>
struct function_traits<R(C::*)> : public function_traits<R(C&)>
{};


bool checkSameAddress(const Matrix& lhs, const Matrix& rhs)
{
    return &lhs == &rhs;
}

const std::string dummyPath = "C:\\Users\\User\\Desktop\\Studies\\Year4\\Semester B\\C_C++\\C++EX1\\relevant files\\tests\\test_files\\binary_im0";


void checkOperatorRead()
{
    std::ifstream dummy_file;
    dummy_file.open(dummyPath, std::ios::in | std::ios::binary);
    Matrix M(28, 28);
    std::cout << "Checking operator >> arguments" << std::endl;
    if ((void*)&dummy_file != (void*)&((dummy_file >> M)))
    {
        dummy_file.close();
        exit(1);
    }
    dummy_file.close();
}

int main()
{
    checkOperatorRead();
    return 0;
}
