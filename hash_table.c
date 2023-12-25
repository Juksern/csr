//hash table
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 1000

struct htitem_t {
	uint64_t key;
	int item;
	int count;
};

struct hash_table_t {
	struct htitem_t** items;
	size_t size;
	int count;
};

uint64_t create_hash(int key) {
	const uint64_t base = 0x01000193;
	uint32_t h = 0x811c9dc5;
	h ^= key;
	h *= base;

	return h % HASH_TABLE_SIZE;
}

struct htitem_t* create_item(int value) {
	struct htitem_t* obj = (struct htitem_t*)malloc(sizeof(*obj));
	obj->item = value;
	obj->key = create_hash(value);
	obj->count = 1;

	return obj;
}

struct hash_table_t* create_table(size_t size) {
	struct hash_table_t* this = (struct hash_table_t*)malloc(sizeof(*this));
	this->size = size;
	this->count = 0;
	this->items = (struct htitem_t**)calloc(this->size, sizeof(struct htitem_t*));

	memset(this->items, 0, sizeof(struct htitem_t*) * this->size);

	return this;
}

void free_table(struct hash_table_t* this) {
	for (size_t i = 0; i < this->size; i++) {
		struct htitem_t* item = this->items[i];

		if (item != NULL)
			free(item);
	}

	free(this->items);
	free(this);
}

void insert(struct hash_table_t* this, struct htitem_t* item) {	
	if (this->items[item->key] == NULL) {
		this->items[item->key] = item;
		this->count += 1;
		return;
	}

	this->items[item->key]->count += 1;
}

struct htitem_t* find(struct hash_table_t* this, int value) {
	return this->items[create_hash(value)];
}

int main() {
	struct hash_table_t* my_table = create_table(HASH_TABLE_SIZE);

	for (int i = 32; i < 126; i++) {
		insert(my_table, create_item(i));
	}

	for(int i = 0; i < my_table->size; i++) {
		struct htitem_t* item = my_table->items[i];

		if (item != NULL)
			printf("%llu: %c %d\n", item->key, item->item, item->count);
	}

	printf("ht_size: %llu, ht_count: %d", my_table->size, my_table->count);

	free_table(my_table);
	return 0;
}
