// C++ function to delete a node at a specific position
Node* deleteAtPosition(Node* head, int position)
{
    // If the list is empty or the position is invalid
    if (head == nullptr || position < 1) {
        return head;
    }

    // If the head needs to be deleted
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Traverse to the node before the position to be
    // deleted
    Node* current = head;
    for (int i = 1; i < position - 1 && current != nullptr;
         i++) {
        current = current->next;
    }

    // If the position is out of range
    if (current == NULL || current->next == nullptr) {
        return;
    }
 
    // Store the node to be deleted
    Node* temp = current->next;

    // Update the links to bypass the node to be deleted
    current->next = current->next->next;

    // Delete the node
    delete temp;
  
    return head;
}