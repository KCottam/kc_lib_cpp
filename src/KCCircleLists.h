#ifndef KCCIRCLELISTS_H
#define KCCIRCLELISTS_H

#include "KCLists.h"

template <class T>
class CircleList final : public List<T>
{
public:
	CircleList();
	CircleList(int length, T const* data);
	explicit CircleList(T const& data);
	CircleList(std::initializer_list<T> data);

	CircleList(CircleList<T> const& other);
	CircleList(CircleList<T>&& other) noexcept;

	CircleList(List<T> const& other);

	auto Push(T const& data) -> void; // operator<<()
	auto Push(int length, T const* data) -> void;
	auto Push(std::initializer_list<T> data) -> void;

	auto Pull() -> T; // operator>>()

	auto operator<<(T const& data) -> CircleList<T>&;
	auto operator<<(std::initializer_list<T> data) -> CircleList<T>&;

	~CircleList();
};

#include "KCCircleLists.hpp"

#endif // !KCCIRCLELISTS_H
