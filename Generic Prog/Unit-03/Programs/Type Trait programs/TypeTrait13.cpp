#include <type_traits>
#include <iostream>
namespace detail
{
	template <bool b>
	struct copy_fn
	{
		template<typename InputIt, typename OutputIt>
		constexpr static OutputIt copy(InputIt first,InputIt last,
					OutputIt d_first)
		{
			while (first != last)
			{
				*d_first++ = *first++;
			}
		return d_first;
		}
	};
	template <>
	struct copy_fn<true>
	{
		template<typename InputIt, typename OutputIt>
		constexpr static OutputIt* copy(InputIt* first, InputIt* last,
				OutputIt* d_first)
		{
			std::memmove(d_first, first,(last - first) * izeof(InputIt));
			return d_first + (last - first);
		}
	};
}