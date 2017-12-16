#ifndef _PIGEON_HH_
#define _PIGEON_HH_ 1

#include <gmpxx.h>

class pigeon {
  class iterator;
 public:
  pigeon(std::size_t = -1) noexcept;
  iterator begin() const noexcept;
  iterator end() const noexcept;
 private:
  class iterator {
   public:
    iterator() noexcept;
    iterator(std::size_t) noexcept;
    long operator*() const noexcept;
    bool operator!=(const iterator &) const noexcept;
    iterator &operator++() noexcept;
    iterator operator++(int) noexcept;
   private:
    mpz_class q, r, t, k, n, l;
    long p;
    std::size_t digits;
  };
  std::size_t digits;
};

pigeon::pigeon(std::size_t digits) noexcept
    : digits{digits} {
}

pigeon::iterator pigeon::begin() const noexcept {
  return pigeon::iterator();
}

pigeon::iterator pigeon::end() const noexcept {
  return pigeon::iterator(this->digits);
}

pigeon::iterator::iterator() noexcept
    : q{10}, r{-30}, t{3}, k{2}, n{0}, l{5}, p{3}, digits{0} {
}

pigeon::iterator::iterator(std::size_t digits) noexcept
    : digits{digits} {
}

long pigeon::iterator::operator*() const noexcept {
  return this->p;
}

bool pigeon::iterator::operator!=(const iterator &that) const noexcept {
  return this->digits != that.digits;
}

pigeon::iterator &pigeon::iterator::operator++() noexcept {
  while (true) {
    if (this->q << 2 < this->n * this->t + this->t - this->r) {
      this->p = n.get_si();
      this->q *= 10;
      this->r -= this->n * this->t;
      this->r *= 10;
      this->n = (3 * this->q + this->r) / this->t;
      ++this->digits;
      break;
    } else {
      this->t *= this->l;
      mpz_class qk = this->q * this->k;
      mpz_class q2 = 2 * this->q;
      mpz_class rx = this->r * this->l;
      this->n = (7 * qk + q2 + rx) / this->t;
      this->r = std::move(rx);
      this->r += q2 * this->l;
      this->q = std::move(qk);
      ++this->k;
      this->l += 2;
    }
  }
  return *this;
}

#endif  // _PIGEON_HH_
