#include <ADS_ForwardList.h>

struct point {
    double x, y;
};

ADS_FORWARD_LIST_DEFINE(struct point, Point)
ADS_FORWARD_LIST_DEFINE(double, Double)

void foo(void)
{
    ADS_ForwardList(Double) list = ADS_ForwardList_Create();

    ADS_ForwardList_PushFront(&list, 1.);
    ADS_ForwardList_PushFront(&list, 2.);
    ADS_ForwardList_PushFront(&list, 3.);
    ADS_ForwardList_PushFront(&list, 4.);
    ADS_ForwardList_PushFront(&list, 5.);

    ADS_ForwardList_Reverse(&list);

    for (ADS_ForwardListNode(Double) *node = ADS_ForwardList_Front(&list);
         node;
         node = node->next)
    {
        printf("Value: %f\n", node->value);
    }

    ADS_ForwardList_Clear(&list);

    /* This statement is true here */
    if (ADS_ForwardList_IsEmpty(&list))
        printf("The list is empty.\n");
}
