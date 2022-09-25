#ifndef String_h
#define String_h

namespace Core {

class String {
public:
  String(const char* value);

  String operator=(const char* value);

  const char* c_str() const;

private:
  const char* _str;
};

}

#endif
