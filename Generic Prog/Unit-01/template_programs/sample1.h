template<typename T, T val>
union A{
   T func();
};
extern template union A<int, 55>;

template<class T, T val>
T A<T,val>::func(void){
   return val;
}
