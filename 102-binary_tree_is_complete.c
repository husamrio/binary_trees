#include "binary_trees.h"

int binary_tree_is_complete(const binary_tree_t *tree);
levelorder_queue_t *create_node(binary_tree_t *node);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
void free_queue(levelorder_queue_t *head);

/**
 * create_node - Generates a new node for a level-order queue data structure.
 *
 *
 * @node: The binary tree node that the new levelorder_queue_t node
 * will contain.
 *
 *
 * Return: If an error occurs during the creation process, the function should
 * return NULL. Otherwise, it should return a pointer to the
 * newly created node.
 *
 *
 */

levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - Deallocates memory associated with a levelorder_queue_t queue.
 *
 *
 * @head: A reference (pointer) to the head of the
 * levelorder_queue_t queue that needs to be freed.
 *
 *
 */

void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * push - Adds a node to the end of a levelorder_queue_t queue.
 *
 *
 * @node: The binary tree node that needs to be printed and
 * pushed into the level-order queue.
 *
 *
 * @head: A reference to a pointer that points to the head
 * of the levelorder_queue_t queue.
 *
 *
 * @tail: A reference to a pointer that points to the tail
 * of the levelorder_queue_t queue.
 * Description Upon malloc failure, exits with a status code of 1.
 *
 *
 */

void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 * pop - Removes the head element from a levelorder_queue_t queue.
 *
 *
 * @head: A reference to a pointer that points to the head of the
 * levelorder_queue_t queue.
 *
 *
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}
/**
 * binary_tree_is_complete - Verifies binary tree completeness.
 *
 *
 * @tree: A reference (pointer) to the root node of the
 *  tree that needs to be traversed.
 *
 *
 * Return: Returns 1 if the tree is complete, else 0.
 *
 * Description Exits with status 1 on malloc failure.
 *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}
