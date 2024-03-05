using namespace std;

// This will be int
conditional<true, int, float>::type

// We can use conditional_t to access ::type directly
// This will be std::string
conditional_t<true, string, char*>

// The bool can be any expression known at compile time
// This will be std::string
constexpr bool useStdString{true};
conditional_t<useStdString, string, char*>

// This will be std::vector<float>
conditional_t<false, vector<int>, vector<float>>

// This will be std::vector<float> too
vector<conditional_t<false, int, float>>