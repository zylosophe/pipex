#include "execcommand.h"
#include "error.h"
#include <unistd.h>

int main()
{
	int		in;
	int		out;
	int		pipe[2];
	char	buf1[] = "----------\n";
	char	buf2[] = "----------\n";
	char	buf3[] = "----------\n";

	startprogram();
	execcommand(pipe, "/bin/cat -");
	write(1, "execcommand() done\n", 19);
	in = pipe[1];
	out = pipe[0];

	write(in, "one", 3);
	write(1, "write() done!\n", 14);
	read(out, buf1, 10);
	write(1, "read() done!\n", 13);
	write(1, buf1, 11);

	write(in, "two", 3);
	read(out, buf2, 10);
	write(1, buf2, 11);

	close(in);
	write(1, "[close]\n", 8);

	read(out, buf3, 10);
	write(1, buf3, 11);
	endprogram();
}
