#include <boost/python.hpp>
using namespace boost::python;

struct Num
{
    Num(const float& val): m_value(val) {};
    float get() const;
    void set(float value);
    float m_value;
};

float Num::get() const
{
    return m_value;
}

void Num::set(float value)
{
    m_value = value;
}

BOOST_PYTHON_MODULE(hello)
{
class_<Num>("Num", init<float>())
    .add_property("rovalue", &Num::get)
    .add_property("value", &Num::get, &Num::set);
}
