#include<type_traits>

template <typename T>
struct remove_pointer;

template <typename T>
struct remove_pointer<T*>{
    using type = T;
};

template <typename T>
struct remove_const;

template <typename T> 
struct remove_const<const T>{
    using type = T;
};

bool Foo(int){}

template <typename T>
struct function_traits;

template<typename Ret,typename Param>
struct function_traits<Ret(*)(Param)>{
    using return_type = Ret;
    using param_type = Param;
};

int main(){
    auto ptr=&Foo;
    using function_info = function_traits<decltype(ptr)>;
    using param=function_info::param_type;
    static_assert(std::is_same_v<param,int>);
    using type = remove_pointer<int*>::type;
    return 0;
}