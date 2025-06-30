class stack
{
public:
    stack(const int& max)
    {
        _max_size = max;
        _top = -1;
        _arr = new int[_max_size];
    }
    ~stack()
    {
        delete[](_arr);
    }

    void push(const int& obj)
    {
        if (_top + 1 < _max_size)
        {
            ++_top;
            _arr[_top] = obj;
        }
        else
        {
            return;
        }
    }
    const int pop()
    {
        if (_top < 0)
        {
            return 0;
        }
        else
        {
            int top_obj = _arr[_top];
            --_top;
            return top_obj;
        }
    }
    const int peek()
    {
        if (_top < 0)
        {
            return 0;
        }
        else
        {
            return _arr[_top];
        }
    }
private:
    int _max_size;
    int _top;
    int* _arr;
};