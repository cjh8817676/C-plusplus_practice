// vect.h -- Vector class with <<, mode state
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

/*向量 有分"直角坐標" 與 "徑度" ， 將2種表示法置於 類別描述當中*/
/*只要向量的表示法改變，物件就會自動更新另一種表示法*/

/*namespace VECTOR 為"名稱空間"， 將類別置於"名稱空間中" */
namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode {RECT, POL};  //RECT:直角坐標  POL:極座標 (一次只能一個表示法，所以用enum)
    // RECT for rectangular, POL for Polar modes
    private:
        double x;          // horizontal value
        double y;          // vertical value
        double mag;        // length of vector
        double ang;        // direction of vector in degrees
        Mode mode;         // RECT(0) or POL(1)
    // private methods for setting values
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
       Vector();
        Vector(double n1, double n2, Mode form = RECT); //預設直角坐標
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const {return x;}       // report x value
        double yval() const {return y;}       // report y value
        double magval() const {return mag;}   // report magnitude
        double angval() const {return ang;}   // report angle
        void polar_mode();                    // set mode to POL
        void rect_mode();                     // set mode to RECT
    // operator overloading
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
    // friends
        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & operator<<(std::ostream & os, const Vector & v); //只需令 << 為Vector的夥伴
    };

}   // end namespace VECTOR
#endif
