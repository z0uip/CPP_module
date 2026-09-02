#ifndef SPAN_HPP
#define SPAN_HPP

class Span
{
	private :
		unsigned int n;
	public :
		Span(int n);
		void addNumber(int num);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		class error
		{
			const char* what() const throw()
			{
				return ("An erroc occured");
			};
		}
};

#endif