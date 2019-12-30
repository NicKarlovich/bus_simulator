
class Point2 {
  private:
    float x_pos;
    float y_pos;
  public:
    float DistanceBetween(Point2 p);
    int Quadrant();
    void Print();
    Point2(float x_ = 0, float y_ = 0);
};
