#include <math.h>

class queue
{
public:
    queue(const int& capacity)
    {
        m_capacity = capacity;
        m_arr = new int[m_capacity] { 0, };
        m_low = 0;
        m_high = 0;
    }
    ~queue()
    {
        delete[] m_arr;
    }

    void push(const int& element)
    {
        int next = (m_high + 1) % (m_capacity + 1);
        if (next == m_low)
        {
            return;
        }
        
        m_arr[m_high] = element;
        m_high = (m_high + 1) % m_capacity;
    }

    int pop()
    {
        int next = (m_low + 1) % (m_capacity + 1);
        if (next == m_high)
        {
            return -1;
        }

        int element = m_arr[m_low];
        m_low = (m_low + 1) % m_capacity;
        
        return element;
    }

private:
    int m_capacity;
    int* m_arr;
    int m_low;
    int m_high;
};
