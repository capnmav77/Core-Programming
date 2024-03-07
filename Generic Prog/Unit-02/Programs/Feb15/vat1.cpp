template<typename T, T... Ints>
struct integer_sequence
{};
template<std::size_t... Ints>
using index_sequence = integer_sequence<std::size_t, Ints...>;
template<typename T, std::size_t N, T... Is>
struct make_integer_sequence :
make_integer_sequence<T, N - 1, N - 1, Is...>
{};
template<typename T, T... Is>
struct make_integer_sequence<T, 0, Is...> :
integer_sequence<T, Is...>
{};
template<std::size_t N>
using make_index_sequence = make_integer_sequence<std::size_t,N>;
template<typename... T>
using index_sequence_for = make_index_sequence<sizeof...(T)>;
