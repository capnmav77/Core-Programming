template <typename T>
class Vector{
    T* vec_data;
    int length;
    int vec_size;
};

template <>
class Vector<bool>{
    unsigned_int* vec_data;
    int length;
    int vec_size;
};

// the specialized version of the vector template can have different data types for the same template

// Compare this snippet from Generic%20Prog/Unit-01/TemplateProg/templatemul.cpp: