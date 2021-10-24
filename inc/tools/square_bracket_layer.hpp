template <class elem_t>
class SquareBracketsLayer
{
private:

    elem_t* data_;

public:

    SquareBracketsLayer()
    {
        data_ = nullptr;
    }

    SquareBracketsLayer(elem_t* data)
    {
        data_ = data;
    }

    elem_t& operator[](int idx)
    {
        return data_[idx];
    }

};
