#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenvir(info_t *info)
{
	print_list_str(info->envir);
	return (0);
}

/**
 * _getenvir - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: envir var name
 *
 * Return: the value
 */
char *_getenvir(info_t *info, const char *name)
{
	list_t *node = info->envir;
	char *pt;

	while (node)
	{
		pt = starts_with(node->str, name);
		if (pt && *pt)
			return (pt);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenvir - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenvit(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("false number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenvir(info_t *info)
{
	int index;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (index = 1; index <= info->argc; index++)
		_unsetenvir(info, info->argv[i]);

	return (0);
}

/**
 * populate_envir_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t index;

	for (index = 0; environ[index]; index++)
		add_node_end(&node, environ[index], 0);
	info->envir = node;
	return (0);
}
