#!/usr/bin/python3
"""
Lockboxes Module

This module provides a function that determines whether all the boxes in a
collection can be opened. Each box may contain zero or more keys, where each key
corresponds to the index of another box. Box 0 is unlocked by default.

The goal is to verify whether all boxes can eventually be opened using the
available keys.

This problem can be interpreted as a graph traversal:
- Each box is a node.
- Each key is a directed edge to another node.
- We must determine whether all nodes are reachable from node 0.
"""


def canUnlockAll(boxes):
    """
    Determines whether all boxes can be opened.

    Each box is indexed from 0 to n - 1 and may contain keys that correspond
    to the indices of other boxes. Box 0 is considered unlocked. A key allows
    access to the box whose index matches its value. Some keys may not match
    any existing box, and some boxes may remain inaccessible if no keys lead
    to them.

    The function performs a traversal by collecting keys and attempting to
    open new boxes until no additional boxes can be opened.

    Args:
        boxes (list[list[int]]): A list of boxes, where each box is represented
            by a list of integer keys. `boxes[i]` contains keys found in box `i`.

    Returns:
        bool: True if all boxes can be opened, False otherwise.

    Raises:
        TypeError: If `boxes` is not a list of lists.
    """

    if not isinstance(boxes, list):
        return False

    number_of_boxes = len(boxes)

    if(number_of_boxes == 0):
        return False

    opened = {0}
    keys_to_use = list(boxes[0])
    
    while(keys_to_use):

        key = keys_to_use.pop()

        if key < 0 or key >= number_of_boxes:
            continue

        if(key in opened):
            continue

        else:
            opened.add(key)

        new_keys = boxes[key]
        
        for keys in new_keys:
            keys_to_use.append(keys)
        
    if len(opened) == number_of_boxes:
        return True
    else:
        return False
