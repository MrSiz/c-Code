size_t strlen(const char* str)
{
	assert(str != nullptr);
	size_t cnt = 0;
	while (*str++)
		++cnt;
	return cnt;
}

void* memmove(void* des, const void* src, size_t num)
{
	assert(des != nullptr && src != nullptr);
	if (des == src || num == 0)
		return des;
	char* d = des;
	const char* s = src;
	if (d < s || d >= s + num)
	{
		while (num--)
		{
			*d++ = *src++;
		}
		return d;
	}
	d += num;
	s += num;
	while (num--)
		*--d = *--s;
	return d;
}

char* strcpy( char* dest, const char* src )
{
	assert(dest != nullptr && src != nullptr);
	while (*dest ++ = *src++);
	return dest;
}

char *strncpy( char *dest, const char *src, std::size_t count )
{
	assert(dest != nullptr && src != nullptr);
	while (num --)
		*des++ = *source++;
	return dest;
}

char *strcat( char *dest, const char *src )
{
	assert(dest != nullptr && src != nullptr);
	char* ptr = dest + strlen(dest);
	while (*ptr++ = *src++);
	return dest;
}