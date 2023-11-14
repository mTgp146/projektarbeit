
class Galaxip {
public:
  Galaxip();

  int getX() const;
  void setX(int x);

  int getY() const;
  void setY(int y);

  void moveLeft();
  void moveRight();

private:
  float x;
  float y;
};
