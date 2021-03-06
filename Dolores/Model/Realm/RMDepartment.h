//
//  RMDepartment.h
//  Dolores
//
//  Created by Heath on 10/05/2017.
//  Copyright © 2017 Facebook. All rights reserved.
//

#import <Realm/Realm.h>
#import "RMStaff.h"

// This protocol enables typed collections. i.e.:
// RLMArray<RMDepartment>
RLM_ARRAY_TYPE(RMDepartment)

/**
 * 部门表
 */
@interface RMDepartment : RLMObject

@property NSString *departmentId; //id
@property NSString *departmentName; //部门名
@property NSString *departmentDes;  //部门描述
@property NSNumber<RLMInt> *priority;//优先级
@property NSString *parentId;

/**
 * 子部门
 */
@property RLMArray<RMDepartment *><RMDepartment> *childrenDepartments;

/**
 * 隶属部门人员
 */
@property RLMArray<RMStaff *><RMStaff> *staffs;

- (instancetype)initWithId:(NSString *)id name:(NSString *)name description:(NSString *)description;

- (RLMResults<RMDepartment *> *)sortedChildDepartments;
- (RLMResults<RMStaff *> *)sortedStaffs;

@end


