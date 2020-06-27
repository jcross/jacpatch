#define VERSION "v0.01"
const char BANNER[] = {
  0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f,
  0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f,
  0x5f, 0x5f, 0x5f, 0x5f, 0x0a, 0x3c, 0x20, 0x4d, 0x61, 0x64, 0x65, 0x20,
  0x77, 0x69, 0x74, 0x68, 0x20, 0x4a, 0x41, 0x43, 0x50, 0x61, 0x74, 0x63,
  0x68, 0x20, 0x25, 0x73, 0x21, 0x20, 0x3e, 0x0a, 0x20, 0x2d, 0x2d, 0x2d,
  0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d,
  0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d,
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x2f, 0x20, 0x5c, 0x20, 0x20, 0x2f, 0x2f, 0x5c,
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x20, 0x20, 0x20,
  0x20, 0x7c, 0x5c, 0x5f, 0x5f, 0x5f, 0x2f, 0x7c, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x2f, 0x20, 0x20, 0x20, 0x5c, 0x2f, 0x2f, 0x20, 0x20, 0x5c,
  0x5c, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x2f, 0x30, 0x20, 0x20, 0x30, 0x20, 0x20, 0x5c, 0x5f, 0x5f,
  0x20, 0x20, 0x2f, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f, 0x20, 0x20, 0x7c,
  0x20, 0x5c, 0x20, 0x5c, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x2f, 0x20, 0x20, 0x5c, 0x2f, 0x5f, 0x2f, 0x20, 0x20, 0x20,
  0x20, 0x2f, 0x2f, 0x20, 0x20, 0x20, 0x7c, 0x20, 0x20, 0x5c, 0x20, 0x20,
  0x5c, 0x20, 0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x40, 0x5f, 0x5e, 0x5f, 0x40, 0x27, 0x2f, 0x20, 0x20,
  0x20, 0x5c, 0x2f, 0x5f, 0x20, 0x20, 0x20, 0x2f, 0x2f, 0x20, 0x20, 0x20,
  0x20, 0x7c, 0x20, 0x20, 0x20, 0x5c, 0x20, 0x20, 0x20, 0x5c, 0x20, 0x0a,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f,
  0x2f, 0x5f, 0x5e, 0x5f, 0x2f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x2f,
  0x5f, 0x20, 0x2f, 0x2f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7c, 0x20, 0x20,
  0x20, 0x20, 0x5c, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x0a, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x28, 0x20, 0x2f, 0x2f, 0x29, 0x20, 0x7c,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x2f, 0x2f, 0x2f,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7c, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x5c, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x0a, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x28, 0x20, 0x2f, 0x20, 0x2f, 0x29, 0x20, 0x5f, 0x7c, 0x5f,
  0x20, 0x2f, 0x20, 0x20, 0x20, 0x29, 0x20, 0x20, 0x2f, 0x2f, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x7c, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x5c, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5f, 0x5c, 0x0a, 0x20, 0x20, 0x20,
  0x20, 0x28, 0x20, 0x2f, 0x2f, 0x20, 0x2f, 0x29, 0x20, 0x27, 0x2f, 0x2c,
  0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x2f, 0x20, 0x20, 0x28, 0x20, 0x3b, 0x20,
  0x2d, 0x2e, 0x20, 0x20, 0x20, 0x20, 0x7c, 0x20, 0x20, 0x20, 0x20, 0x5f,
  0x20, 0x5f, 0x5c, 0x2e, 0x2d, 0x7e, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x2e, 0x2d, 0x7e, 0x7e, 0x7e, 0x5e, 0x2d, 0x2e, 0x0a, 0x20,
  0x20, 0x28, 0x28, 0x20, 0x2f, 0x20, 0x2f, 0x20, 0x29, 0x29, 0x20, 0x2c,
  0x2d, 0x7b, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5f, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x60, 0x2d, 0x2e, 0x7c, 0x2e, 0x2d, 0x7e,
  0x2d, 0x2e, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x2e, 0x7e, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x60, 0x2e, 0x0a, 0x20, 0x28, 0x28, 0x20, 0x2f, 0x2f, 0x20, 0x2f, 0x20,
  0x29, 0x29, 0x20, 0x20, 0x27, 0x2f, 0x5c, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x2f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7e, 0x2d, 0x2e, 0x20, 0x5f,
  0x20, 0x2e, 0x2d, 0x7e, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2e, 0x2d,
  0x7e, 0x5e, 0x2d, 0x2e, 0x20, 0x20, 0x5c, 0x0a, 0x20, 0x28, 0x28, 0x20,
  0x2f, 0x2f, 0x2f, 0x20, 0x29, 0x29, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x60, 0x2e, 0x20, 0x20, 0x20, 0x7b, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7d, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x2f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x20, 0x20,
  0x5c, 0x0a, 0x20, 0x20, 0x28, 0x28, 0x20, 0x2f, 0x20, 0x29, 0x29, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x2e, 0x2d, 0x2d, 0x2d, 0x2d, 0x7e, 0x2d, 0x2e,
  0x5c, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5c, 0x2d, 0x27,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x2e, 0x7e, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x5c, 0x20, 0x20, 0x60, 0x2e, 0x20, 0x5c, 0x5e,
  0x2d, 0x2e, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f, 0x2f, 0x2e, 0x2d, 0x2d, 0x2d, 0x2d,
  0x2e, 0x2e, 0x3e, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5c,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x5f, 0x20, 0x2d, 0x7e, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x60, 0x2e, 0x20, 0x20, 0x5e, 0x2d,
  0x60, 0x20, 0x20, 0x5e, 0x2d, 0x5f, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f,
  0x2f, 0x2d, 0x2e, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f,
  0x20, 0x5f, 0x20, 0x5f, 0x7d, 0x5e, 0x20, 0x2d, 0x20, 0x2d, 0x20, 0x2d,
  0x20, 0x2d, 0x20, 0x7e, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x7e, 0x2d, 0x2d, 0x20, 0x2c, 0x2e, 0x2d, 0x7e, 0x0a, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x2f, 0x2e, 0x2d, 0x7e, 0x0a
};
