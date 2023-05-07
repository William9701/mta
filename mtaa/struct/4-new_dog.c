#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

dog_t *new_dog(char *name, float age, char *owner)
{
	int i;
	int j;
	dog_t *dog;

	i = strlen(name);
	j = strlen(owner);

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
	{
		return NULL;
	}

	dog->name = malloc(sizeof(char) * (i + 1));
	if (dog->name == NULL)
	{
		free(dog->name);
		return NULL;
	}
	dog->owner = malloc(sizeof(char) * (j + 1));
	if (dog->owner == NULL)
	{
		free(dog);
		free(dog->name);
		return NULL;
	}
	strcpy(dog->name, name);
	strcpy(dog->owner, owner);
	dog->age = age;

	return dog;
}
