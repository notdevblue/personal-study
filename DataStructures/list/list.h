class list
{
private:
    class list_element;

public:
    list();
    ~list();

    void push_front(const int &element);
    void push_back(const int &element);

    const int& front() const;
    const int& back() const;
    void pop();

    const int& operator[](const int&) const;

private:
    list_element *_front;
    list_element *_back;

    class list_element
    {
    public:
        list_element() : _element(0), _next(nullptr), _prev(nullptr)
        {
        }
        list_element(const int element, list_element *next, list_element *prev) : _element(element), _next(next), _prev(prev)
        {
        }

        list_element *get_next() const
        {
            return _next;
        }

        void set_next(list_element *next)
        {
            _next = next;
        }

        list_element *get_prev() const
        {
            return _prev;
        }

        void set_prev(list_element *prev)
        {
            _prev = prev;
        }

        const int& get_element()
        {
            return _element;
        }

    private:
        const int _element;
        list_element *_next;
        list_element *_prev;
    };
};
