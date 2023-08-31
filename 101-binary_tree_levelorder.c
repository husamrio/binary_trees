#include "binary_trees.h"

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
levelorder_queue_t *create_node(binary_tree_t *node);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void free_queue(levelorder_queue_t *head);


/**
 * create_node - Generates a new node for a level-order
 * queue data structure.
 *
 *
 * @node: The binary tree node that the new levelorder_queue_t
 * node will contain.
 *
 *
 * Return: If an error occurs during the creation process,
 *  the function should return NULL.
 *
 *
 * Otherwise, the function should return a pointer
 * to the newly created node.
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
 * free_queue - Deallocates memory associated with
 * a levelorder_queue_t queue.
 *
 *
 * @head:A reference (pointer) to the head of the levelorder_queue_t
 * queue that needs to be freed.
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
 * pint_push - Executes a specified function on a provided binary
 * tree node and then adds its children to a level-order queue.
 *
 *
 * @node: The binary tree node that needs to be printed and
 * whose children should be pushed into the level-order queue.
 *
 *
 * @head: A reference to a pointer that points to the head
 * of the levelorder_queue_t queue.
 *
 *
 * @tail: A reference to a pointer that points to the tail
 *  of the levelorder_queue_t queue.
 *
 *
 * @func: A reference (pointer) to the function that
 *        needs to be called on the provided node.
 *
 *
 */

void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * pop - Removes the head element from a levelorder_queue_t queue.
 *
 *
 * @head: A reference to a pointer that points to the head
 *  of the levelorder_queue_t queue.
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
 * binary_tree_levelorder - Performs a traversal of a binary tree
 * using level-order traversal technique.
 *
 *
 * @tree: A reference (pointer) to the root node of the binary tree
 * that needs to be traversed using level-order traversal.
 *
 *
 * @func: A reference (pointer) to a function that will be called
 * for each node during the level-order traversal.
 *
 *
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}
